/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fviolin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/28 16:08:14 by fviolin           #+#    #+#             */
/*   Updated: 2016/07/31 22:24:22 by gwells           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>
#include <builtins.h>

static int	read_export_options(char **cmd, int i, int j)
{
	int opt;

	opt = 1;
	while (cmd[++i])
	{
		if (cmd[i][0] == '-')
		{
			j = 0;
			while (cmd[i][++j])
			{
				if (cmd[i][j] == 'p')
					opt = 0;
				else
					return (-1);
			}
		}
		else
			break ;
	}
	if (!opt)
		return (opt);
	return (i);
}

static void	read_export_args(t_input *i, t_env **e, t_var **v, char *cmd)
{
	t_var	*cur;
	char	**res;
	char	*tmp;

	res = NULL;
	res = read_export_args_norme(res, cmd, v);
	if (res)
	{
		do_setenv(i, e, v, res);
		if (*v)
		{
			cur = *v;
			while (cur)
			{
				tmp = ft_strjoin(res[1], "=");
				if (!ft_strcmp(cur->name, tmp))
					cur->exported = 1;
				cur = cur->next;
				free(tmp);
			}
		}
		ft_freetab(res);
	}
}

int			do_export(t_input *input, t_env **env, t_var **var, char **cmd)
{
	int	i;

	if (ft_tablen(cmd) < 2)
		print_vars(*var, 0);
	else
	{
		if ((i = read_export_options(cmd, 0, 0)) == -1)
			return (error_export(0));
		if (i == 0)
		{
			print_vars(*var, 1);
			return (0);
		}
		while (cmd[i])
		{
			read_export_args(input, env, var, cmd[i]);
			i++;
		}
	}
	return (0);
}
