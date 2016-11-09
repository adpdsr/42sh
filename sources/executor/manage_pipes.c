/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_pipes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adu-pelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/25 09:22:41 by adu-pelo          #+#    #+#             */
/*   Updated: 2016/09/09 10:05:08 by fviolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>
#include <processes.h>

static void	supress_next_node(t_parser *processes)
{
	t_parser	*next;

	if (processes->next->next)
	{
		next = processes->next;
		ft_freetab(next->content);
		processes->next = processes->next->next;
		free(next);
	}
}

int			redir_to_pipes(t_all *all, t_parser *processes)
{
	if (processes->token == LESS)
	{
		if (do_redir_input(all, processes) == -1)
		{
			supress_next_node(processes);
			return (-1);
		}
	}
	else if (processes->token == DLESS)
	{
		if (do_heredoc(all, processes) == -1)
		{
			supress_next_node(processes);
			return (-1);
		}
	}
	processes->token = processes->next->token;
	supress_next_node(processes);
	return (0);
}

int			do_pipes(t_all *all, t_parser *processes)
{
	int				status;
	t_signal_var	*s;

	s = singleton();
	s->ret = 0;
	if (!processes->content[0])
		return (-1);
	pipe(all->exec->fd);
	all->exec->pid = fork();
	if (all->exec->pid == 0)
	{
		dup2(all->exec->fd[1], processes->r_stdout);
		close(all->exec->fd[0]);
		if ((s->ret = exec_processes(all, processes) >= 0))
			exit(s->ret);
	}
	else if (all->exec->pid > 0)
	{
		close(all->exec->fd[1]);
		dup2(all->exec->fd[0], processes->r_stdin);
		close(all->exec->fd[0]);
		waitpid(all->exec->pid, &status, 0);
	}
	return (s->ret);
}
