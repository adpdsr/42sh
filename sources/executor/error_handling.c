/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fviolin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/28 16:26:46 by fviolin           #+#    #+#             */
/*   Updated: 2016/08/09 18:55:16 by fviolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>
#include <processes.h>
#include <builtins.h>

int			check_file_access(char *path)
{
	struct stat	sb;

	stat(path, &sb);
	if (access(path, F_OK) == -1)
		return (127);
	else if (access(path, X_OK) == -1)
		return (126);
	else if (S_ISDIR(sb.st_mode))
		return (2);
	return (0);
}

int			check_error_execute(t_all *all, t_parser *processes, char *path)
{
	int		ret;
	char	*res;

	ret = 0;
	res = ft_strnstr(processes->content[0], "./", 2);
	if ((ret = check_file_access(path)) || res == NULL)
	{
		dup2(all->exec->stdin_cp, 0);
		ft_putstr_fd("42sh: ", 2);
		ft_putstr_fd(processes->content[0], 2);
		if (ret == 126)
			ft_putendl_fd(": permission denied", 2);
		else
			ft_putendl_fd(": command not found", 2);
		return ((res == NULL) ? 127 : ret);
	}
	return (0);
}

static int	error_output(t_all *all)
{
	ft_putendl_fd("42sh: Ambiguous input redirect.", 2);
	close_fds(all);
	return (-1);
}

static int	check_error(t_parser *process)
{
	while (process)
	{
		if (process->token == PIPE && process->next &&
				!process->next->content[0])
		{
			ft_putendl_fd("42sh: syntax error new unexpected token.", 2);
			return (-1);
		}
		process = process->next;
	}
	return (0);
}

int			error_handling_parser(t_all *all, t_parser *process)
{
	t_signal_var *s;

	s = singleton();
	if (check_error(process) == -1)
		return (-1);
	if (process->token == ERROR && (s->ret = 1))
	{
		ft_putendl_fd("42sh: Invalid null command", 2);
		return (-1);
	}
	while (process->token == PIPE)
	{
		if (process->next && (process->next->token == DLESS ||
					process->next->token == LESS))
			if (error_output(all) == -1)
				return (-1);
		if (!process->next && process->token == PIPE)
			if (error_output(all) == -1)
				return (-1);
		process = process->next;
	}
	return (0);
}
