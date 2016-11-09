/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adu-pelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/27 17:50:19 by adu-pelo          #+#    #+#             */
/*   Updated: 2016/07/31 22:27:00 by gwells           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>
#include <builtins.h>

static int	exist(t_env **head, char *s)
{
	char	*cpy;
	t_env	*tmp;

	tmp = *head;
	cpy = ft_strjoin(s, "=");
	while (tmp)
	{
		if (!ft_strcmp(tmp->name, cpy))
		{
			ft_strdel(&cpy);
			return (1);
		}
		tmp = tmp->next;
	}
	ft_strdel(&cpy);
	return (0);
}

static void	replace_content(t_env **head, char **s1, char **s2)
{
	char	*cpy;
	t_env	*tmp;

	tmp = *head;
	cpy = ft_strdup(*s1);
	ft_strdel(s1);
	*s1 = ft_strjoin(cpy, "=");
	ft_strdel(&cpy);
	while (tmp)
	{
		if (!ft_strcmp(tmp->name, *s1))
		{
			free(tmp->content);
			tmp->content = ft_strdup(*s2);
			break ;
		}
		tmp = tmp->next;
	}
}

static int	read_name(t_env **env, char **cmd, int len)
{
	char	*cpy;
	char	*cmd2;

	cmd2 = ft_strdup("");
	if (len == 2)
	{
		if (exist(env, cmd[1]))
			replace_content(env, &cmd[1], &cmd2);
		else
		{
			cpy = ft_strjoin(cmd[1], "=");
			ft_strdel(&cmd[1]);
			cmd[1] = ft_strdup(cpy);
			ft_strdel(&cpy);
			env_push_back(env, env_create_node(cmd[1]));
		}
		free(cmd2);
		return (0);
	}
	free(cmd2);
	return (1);
}

static int	read_name_value(t_env **env, char **cmd, int len)
{
	char	*cpy;

	if (len == 3)
	{
		if (exist(env, cmd[1]))
			replace_content(env, &cmd[1], &cmd[2]);
		else
		{
			cpy = ft_strjoin(cmd[1], "=");
			ft_strdel(&cmd[1]);
			cmd[1] = ft_strdup(cpy);
			ft_strdel(&cpy);
			cpy = ft_strjoin(cmd[1], cmd[2]);
			ft_strdel(&cmd[1]);
			cmd[1] = ft_strdup(cpy);
			ft_strdel(&cpy);
			env_push_back(env, env_create_node(cmd[1]));
		}
		return (0);
	}
	return (1);
}

int			do_setenv(t_input *input, t_env **env, t_var **var, char **cmd)
{
	int len;

	(void)var;
	(void)input;
	len = ft_tablen(cmd);
	if (len == 1)
		print_env(*env);
	else if (ft_isstralnum(cmd[1]))
	{
		if (!read_name(env, cmd, len) || !read_name_value(env, cmd, len))
			return (1);
		return (error_setenv(0));
	}
	else
		return (error_setenv(1));
	return (0);
}
