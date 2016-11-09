/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers_redirections.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adu-pelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/24 20:20:09 by adu-pelo          #+#    #+#             */
/*   Updated: 2016/07/24 20:20:11 by adu-pelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>
#include <processes.h>

static int	shut_fd_redir_input(t_all *all, t_parser *processes)
{
	if (processes->next)
		all->exec->fd_write = 0;
	else
		all->exec->fd_write = processes->r_stdin;
	close(all->exec->fd_write);
	return (0);
}

static int	update_fds_input(t_all *all, t_parser *processes)
{
	if (processes->r_shutout_in == 1)
		shut_fd_redir_input(all, processes);
	if (processes->next)
	{
		if ((all->exec->fd_read = open(processes->next->content[0],
						O_RDONLY, 0644)) == -1)
		{
			ft_putstr_fd("42sh: ", 2);
			ft_putstr_fd(processes->next->content[0], 2);
			ft_putendl_fd(": No such file or directory", 2);
			return (-1);
		}
		if ((dup2(all->exec->fd_read, processes->r_stdin)) == -1)
			return (-1);
	}
	return (0);
}

int			update_fds_output(t_all *all, t_parser *processes)
{
	if (processes->r_shutout_out == 1)
	{
		close(processes->r_stdout);
		return (0);
	}
	if (processes->next)
	{
		if ((dup2(all->exec->fd_write, processes->r_stdout)) == -1)
			return (-1);
		close(all->exec->fd_write);
	}
	return (0);
}

void		do_redir_output(t_all *all, t_parser *processes)
{
	if (processes->next && (processes->next->token == GREAT ||
				processes->next->token == DGREAT))
		update_fds_output(all, processes->next);
	else
		update_fds_output(all, processes);
}

int			do_redir_input(t_all *all, t_parser *processes)
{
	if (processes->next && (processes->next->token == GREAT
				|| processes->next->token == DGREAT))
		update_fds_output(all, processes->next);
	if (update_fds_input(all, processes) == -1)
		return (-1);
	return (0);
}
