/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adu-pelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/24 11:46:50 by adu-pelo          #+#    #+#             */
/*   Updated: 2016/07/31 22:30:36 by gwells           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>
#include <builtins.h>
#include <processes.h>

t_env		*list_cpy(t_env **head, t_env *new, t_env *elem, t_env *prev_elem)
{
	t_env	*cur;

	cur = *head;
	while (cur)
	{
		if (!(elem = (t_env *)malloc(sizeof(t_env))))
			exit(1);
		elem->name = ft_strdup(cur->name);
		if (cur->content)
			elem->content = ft_strdup(cur->content);
		elem->next = NULL;
		if (!new)
		{
			new = elem;
			prev_elem = elem;
		}
		else
		{
			prev_elem->next = elem;
			prev_elem = elem;
		}
		cur = cur->next;
	}
	return (new);
}

void		print_env(t_env *head)
{
	while (head)
	{
		ft_putstr(head->name);
		ft_putstr(head->content);
		ft_putchar('\n');
		head = head->next;
	}
}

char		*get_binary_path(t_env *new, char **cmd, int i)
{
	char	*content;
	char	*path;
	char	**path_tab;
	char	*full_path;

	content = NULL;
	content = get_node_content(new, "PATH=");
	if (content)
		path_tab = ft_strsplit(content, ':');
	else
		path_tab = NULL;
	free(content);
	path = get_cmd_path(cmd[i], path_tab);
	ft_freetab(path_tab);
	full_path = add_full_path(cmd + i, path);
	ft_strdel(&path);
	return (full_path);
}

int			try_fork_bin(t_env *new, char **cmd, int i)
{
	int		pid;
	int		status;
	char	*full_path;

	full_path = get_binary_path(new, cmd, i);
	if (check_file_access(full_path) != 0)
	{
		free(full_path);
		return (-1);
	}
	else if ((pid = fork()) == -1)
	{
		ft_error("42sh: env: command execution failed", 0);
		free(full_path);
		return (-1);
	}
	if ((pid == 0) && (execve(full_path, cmd + i, list_in_tab(new)) == -1))
		return (-1);
	else if (pid > 0)
	{
		waitpid(pid, &status, 0);
		free(full_path);
		return (check_status(status));
	}
	return (0);
}
