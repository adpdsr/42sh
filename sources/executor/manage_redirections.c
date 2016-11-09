/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_redirections.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adu-pelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/24 20:21:02 by adu-pelo          #+#    #+#             */
/*   Updated: 2016/09/08 13:20:48 by fviolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>
#include <processes.h>
#include <builtins.h>

int			do_heredoc(t_all *all, t_parser *process)
{
	if (process->next && (process->next->token == GREAT ||
				process->next->token == DGREAT))
		update_fds_output(all, process->next);
	if ((dup2(all->exec->fd_read, process->r_stdin)) == -1)
		return (-1);
	close(all->exec->fd_read);
	return (0);
}

static int	exec_redir_fork(t_all *all, t_parser *process)
{
	int ret;

	ret = -1;
	if (process->token == LESS)
	{
		if (do_redir_input(all, process) == -1)
			return (1);
	}
	else if (process->token == DLESS)
		do_heredoc(all, process);
	else if (process->token == GREAT || process->token == DGREAT)
		do_redir_output(all, process);
	if ((ret = exec_processes(all, process)) >= 0)
		return (ret);
	return (-1);
}

static int	manage_agreg_piped(t_all *all, t_parser *process)
{
	if (process->next && process->next->token == PIPE)
	{
		if ((process->token == 1 || process->token == 4)
				&& all->exec->fd_write != 2)
		{
			redir_to_pipes(all, process);
			return (1);
		}
		else if (!process->r_shutout_out && all->exec->fd_write == 1)
		{
			redir_to_pipes(all, process);
			return (1);
		}
	}
	return (0);
}

void		exec_redir_processes(t_all *all, t_parser *process)
{
	t_signal_var	*s;
	int				ret;
	int				status;

	status = 0;
	s = singleton();
	if (manage_agreg_piped(all, process))
		return ;
	else if (process->content[0])
	{
		all->exec->pid = fork();
		if (all->exec->pid == 0)
		{
			ret = exec_redir_fork(all, process);
			if (ret >= 0)
				exit(ret);
		}
		else if (all->exec->pid > 0)
		{
			waitpid(all->exec->pid, &status, 0);
			s->ret = check_status(status);
		}
	}
}

t_parser	*manage_redirs_processes(t_all *all, t_parser *process)
{
	if (process->token >= 1 && process->token <= 3)
	{
		exec_redir_processes(all, process);
		if (process->token == GREAT || process->token == DGREAT)
		{
			if ((dup2(all->exec->stdin_cp, 0)) == -1)
				ft_putendl_fd("42sh: dup2 error", 2);
		}
	}
	else if (process->token == DLESS)
		heredoc_process(process, all);
	if (process->next && (process->token == LESS ||
				process->token == DLESS))
		process = process->next;
	while (process->next && (process->token == GREAT ||
				process->token == DGREAT))
		process = process->next;
	return (process);
}
