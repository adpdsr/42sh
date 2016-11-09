/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adu-pelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/24 20:20:20 by adu-pelo          #+#    #+#             */
/*   Updated: 2016/08/09 12:03:08 by fviolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <processes.h>
#include <lineedit.h>

static int	heredoc_error(t_parser *processes, char *line)
{
	if (!processes->next || !ft_strlen(processes->next->content[0]))
	{
		ft_putendl_fd("42sh : syntax error near unexpected token `newline'", 2);
		ft_strdel(&line);
		return (-1);
	}
	return (0);
}

void		heredoc_process(t_parser *processes, t_all *all)
{
	char	*line;
	int		pipe_fd[2];

	line = ft_strdup("");
	pipe(pipe_fd);
	if (heredoc_error(processes, line) == -1)
		return ;
	while (ft_strcmp(line, processes->next->content[0]))
	{
		ft_putstr("heredoc>");
		free(line);
		if (get_next_line(0, &line) < 1)
		{
			ft_putendl("");
			break ;
		}
		if (line && ft_strcmp(line, processes->next->content[0]))
		{
			write(pipe_fd[1], line, ft_strlen(line));
			write(pipe_fd[1], "\n", 1);
		}
	}
	all->exec->fd_read = pipe_fd[0];
	close(pipe_fd[1]);
	exec_redir_processes(all, processes);
}
