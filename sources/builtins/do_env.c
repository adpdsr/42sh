/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fviolin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/28 16:07:24 by fviolin           #+#    #+#             */
/*   Updated: 2016/08/09 11:54:20 by fviolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>
#include <builtins.h>
#include <processes.h>

static t_env	*redirect_unsetenv(t_input *i, t_env **n, t_var **v, char *cmd)
{
	char	**tmp;

	if (!(tmp = (char **)malloc(sizeof(char *) * 3)))
		ft_error("malloc: in redirect_unsetenv", 1);
	tmp[0] = ft_strdup("unsetenv");
	tmp[1] = ft_strdup(cmd);
	tmp[2] = NULL;
	do_unsetenv(i, n, v, tmp);
	ft_freetab(tmp);
	return (*n);
}

static t_env	*redirect_setenv(t_input *i, t_env **n, char *ocmd, t_var **v)
{
	char	**cmd;
	char	**split;

	if (!(cmd = (char **)malloc(sizeof(char *) * 4)))
		ft_error("malloc: in redirect_setenv", 1);
	split = ft_strsplit(ocmd, '=');
	cmd[0] = ft_strdup("setenv");
	cmd[1] = ft_strdup(split[0]);
	if (split[1])
	{
		cmd[2] = ft_strdup(split[1]);
		cmd[3] = NULL;
	}
	else
		cmd[2] = NULL;
	do_setenv(i, n, v, cmd);
	ft_freetab(cmd);
	ft_freetab(split);
	return (*n);
}

static int		read_env_options(char **cmd, int *opt, int i)
{
	int j;

	opt[0] = 0;
	opt[1] = 0;
	while (cmd[++i])
	{
		if (cmd[i][0] == '-')
		{
			j = 0;
			while (cmd[i][++j])
			{
				if (cmd[i][j] == 'u')
					opt[0] = 1;
				else if (cmd[i][j] == 'i')
					opt[1] = 1;
				else
					return (-1);
			}
		}
		else
			return (i);
	}
	return (i);
}

int				free_env_list(t_env **list)
{
	t_env *next;

	if (list)
	{
		while (*list)
		{
			next = (*list)->next;
			free((*list)->name);
			free((*list)->content);
			free(*list);
			*list = next;
		}
	}
	return (1);
}

int				do_env(t_input *input, t_env **env, t_var **var, char **cmd)
{
	int		i;
	int		res;
	int		opt[2];
	t_env	*new;

	new = NULL;
	if ((i = read_env_options(cmd, opt, 0)) == -1)
		return (error_env(0));
	if ((i--) && opt[1] == 0)
		new = list_cpy(env, NULL, NULL, NULL);
	while (cmd[++i])
	{
		if ((res = try_fork_bin(new, cmd, i)) >= 0 && free_env_list(&new))
			return (res);
		else if (opt[0])
			new = redirect_unsetenv(input, &new, var, cmd[i]);
		if (!opt[0] && ft_cntc(cmd[i], '='))
			new = redirect_setenv(input, &new, cmd[i], var);
		else if (!opt[0] && free_env_list(&new))
			return (error_env(1));
	}
	print_env(new);
	free_env_list(&new);
	return (0);
}
