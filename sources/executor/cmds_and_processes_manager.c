/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmds_and_processes_manager.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwells <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/24 14:00:24 by gwells            #+#    #+#             */
/*   Updated: 2016/09/09 10:02:29 by fviolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>
#include <builtins.h>
#include <processes.h>

static t_parser	*get_redirections(t_all *all, t_parser *process)
{
	process = manage_redirs_processes(all, process);
	if (process->next && process->token != PIPE && process->token != AND
			&& process->token != OR)
		process = process->next;
	else if (process->token != PIPE && process->token != AND
			&& process->token != OR)
		return (process);
	return (process);
}

static int		manage_process(t_all *all, t_parser *process, int ret, int flag)
{
	int logic;

	while (process)
	{
		flag = 0;
		logic = 0;
		if (process->token >= 1 && process->token <= 4 && (flag = 1))
		{
			logic = 1;
			process = get_redirections(all, process);
			if (!process->next)
				break ;
		}
		if (process->token == PIPE && (flag = 1))
			if ((ret = do_pipes(all, process)) == -1)
				break ;
		if ((process->token == OR || process->token == AND) && (flag = 1))
			process = manage_logical_operators(all, process, logic);
		if (!flag && process->content[0])
			if ((ret = exec_commands(all, process)) > 0)
				return (ret);
		process = process->next;
	}
	return (ret);
}

static int		manage_multi_commands(t_all *all, t_parser *process)
{
	t_signal_var	*s;
	int				ret;
	int				flag;

	ret = 0;
	flag = 0;
	s = singleton();
	ret = manage_process(all, process, ret, flag);
	if (ret)
		s->ret = ret;
	else
		ret = s->ret;
	return (ret);
}

static int		manage_single_command(t_all *all, t_parser *process,
		int redir, int ret)
{
	t_signal_var *s;

	s = singleton();
	if (process->token >= 1 && process->token <= 4 && (redir = 1))
		process = manage_redirs_processes(all, process);
	if (ret == 0 && !redir && process->content[0])
	{
		ret = exec_commands(all, process);
		s->ret = ret;
	}
	return (0);
}

int				execute_manager(t_all *all, t_parser *process)
{
	t_signal_var	*s;
	int				ret_val;
	int				redir;

	redir = 0;
	ret_val = 0;
	s = singleton();
	all->exec->stdin_cp = dup(0);
	if (error_handling_parser(all, process) == -1)
	{
		close_fds(all);
		return (-1);
	}
	if (process->token == DOLLAR)
		ft_putendl_fd(process->content[0], 1);
	else if (!process->next)
		manage_single_command(all, process, redir, ret_val);
	else
		s->ret = manage_multi_commands(all, process);
	close_fds(all);
	return (ret_val);
}
