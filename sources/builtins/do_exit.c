/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adu-pelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/27 15:53:47 by adu-pelo          #+#    #+#             */
/*   Updated: 2016/09/07 10:45:08 by fviolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>
#include <builtins.h>

static int	error_exit(void)
{
	ft_error("42sh: exit: code must be a number", 0);
	ft_error("42sh: exit: usage: exit [number]", 0);
	return (1);
}

int			do_exit(t_input *input, t_env **env, t_var **var, char **cmd)
{
	int				i;
	int				len;
	int				exit_code;
	t_signal_var	*s;

	i = -1;
	(void)input;
	exit_code = 0;
	len = ft_tablen(cmd);
	s = singleton();
	if (len >= 2)
	{
		while (cmd[1][++i])
		{
			if (!ft_isdigit(cmd[1][i]))
				return (error_exit());
		}
		exit_code = ft_atoi(cmd[1]);
	}
	append_history(s->input->history, s->env);
	ft_freetab(cmd);
	free_prog(var, env);
	exit(exit_code);
	return (exit_code);
}
