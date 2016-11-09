/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_logical_operators.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwells <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/24 14:04:45 by gwells            #+#    #+#             */
/*   Updated: 2016/09/08 20:10:48 by fviolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>
#include <processes.h>
#include <builtins.h>

static int			exec_logical_or(t_all *all, t_parser *process, int redir)
{
	t_signal_var	*s;
	int				ret;

	ret = 0;
	s = singleton();
	if (process->token == OR && process->content[0])
	{
		if (redir == 1 && s->ret == 0)
			return (2);
		else if (redir == 1 && (s->ret == 1 || s->ret == 127))
			return (-1);
		else if (!(ret = exec_commands(all, process)))
		{
			s->ret = ret;
			return (2);
		}
	}
	s->ret = 0;
	return (0);
}

static int			exec_logical_and(t_all *all, t_parser *process, int redir)
{
	t_signal_var	*s;
	int				ret;

	s = singleton();
	ret = 0;
	if (process->token == AND && process->content[0])
	{
		if (redir == 1 && s->ret == 0)
			return (-1);
		else if (redir == 1 && (s->ret == 1 || s->ret == 127))
			return (1);
		else if ((ret = exec_commands(all, process)))
		{
			s->ret = ret;
			return (1);
		}
	}
	s->ret = 0;
	return (0);
}

t_parser			*manage_logical_operators(t_all *all\
, t_parser *process, int redir)
{
	int				oper;

	if (process->token == AND)
		oper = exec_logical_and(all, process, redir);
	if (process->token == OR)
		oper = exec_logical_or(all, process, redir);
	if (oper == 1)
	{
		while (process->next && (process->token == AND || process->token == PIPE
				|| process->token == GREAT || process->token == DGREAT))
			process = process->next;
	}
	else if (oper == 2)
	{
		while (process->next && (process->token == OR || process->token == PIPE
				|| process->token == GREAT || process->token == DGREAT))
			process = process->next;
	}
	return (process);
}
