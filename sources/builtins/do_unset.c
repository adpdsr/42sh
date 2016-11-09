/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fviolin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/28 16:17:30 by fviolin           #+#    #+#             */
/*   Updated: 2016/07/31 22:35:13 by gwells           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>
#include <builtins.h>

static int	read_unset_options(char **cmd, int *opt)
{
	int i;
	int j;

	i = 0;
	opt[0] = 0;
	opt[1] = 0;
	while (cmd[++i])
	{
		if (cmd[i][0] == '-')
		{
			j = 0;
			while (cmd[i][++j])
			{
				if (cmd[i][j] == 'v')
					opt[0] = 1;
				else if (cmd[i][j] == 'f')
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

int			do_unset(t_input *input, t_env **env, t_var **var, char **cmd)
{
	int i;
	int	opt[2];

	i = 0;
	(void)env;
	(void)input;
	if (ft_tablen(cmd) > 1)
	{
		if ((i = read_unset_options(cmd, opt)) == -1)
			return (error_unset(0));
		while (cmd[i])
		{
			delete_var_node(var, *var, cmd[i], opt);
			i++;
		}
	}
	else
		return (error_unset(0));
	return (0);
}
