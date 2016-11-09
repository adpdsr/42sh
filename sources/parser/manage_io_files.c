/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_io_files.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adu-pelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/25 09:13:22 by adu-pelo          #+#    #+#             */
/*   Updated: 2016/07/31 22:10:20 by gwells           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>
#include <processes.h>

static int	get_fds_output(t_all *all, t_parser *process, int i, char *str)
{
	int len;

	len = count_fd_digit_len(str, i);
	if (!i && len == 1)
		process->r_stdout = ft_atoi(&str[i]);
	else if (len == 1 && (ft_atoi(&str[i]) >= 0 && ft_atoi(&str[i]) <= 2))
		all->exec->fd_write = ft_atoi(&str[i]);
	else
	{
		process->r_shutout_out = 1;
		ft_putendl_fd("42sh: bad file descriptor.", 2);
		return (-1);
	}
	return (0);
}

static int	io_file_output(t_all *all, t_parser *process,
		t_lexer *list_lex, char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]))
		{
			if (get_fds_output(all, process, i, str) == -1)
				return (-1);
		}
		if (str[i] == '-')
			process->r_shutout_out = 1;
		i++;
	}
	if (list_lex->next && process->token != LESS)
		open_file_for_redir(all, list_lex);
	return (0);
}

static int	get_fds_input(t_all *all, t_parser *process, int i, char *str)
{
	int len;

	len = count_fd_digit_len(str, i);
	if (!i && len == 1 && (ft_atoi(&str[i]) >= 0 && ft_atoi(&str[i]) <= 9))
		process->r_stdin = ft_atoi(&str[i]);
	else if (len == 1 && (ft_atoi(&str[i]) >= 0 && ft_atoi(&str[i]) <= 2))
	{
		process->r_stdin = 0;
		all->exec->fd_write = ft_atoi(&str[i]);
	}
	else
	{
		ft_putendl_fd("42sh: bad file descriptor.", 2);
		return (-1);
	}
	return (0);
}

static int	io_file_input(t_all *all, t_parser *process, char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]))
		{
			if (get_fds_input(all, process, i, str) == -1)
				return (-1);
		}
		if (str[i] == '-')
			process->r_shutout_in = 1;
		i++;
	}
	return (0);
}

int			manage_io_files(t_all *all, t_lexer *list,\
	t_parser *process, int token)
{
	if (token == GREAT || token == DGREAT)
	{
		while (process->next)
			process = process->next;
		if (io_file_output(all, process, list, list->content) == -1)
			return (-1);
	}
	else if (token == LESS || token == DLESS)
	{
		while (process->next)
		{
			if (process->token == LESS || process->token == DLESS)
			{
				ft_putendl_fd("42sh: Ambiguous input redirect.", 2);
				return (-2);
			}
			process = process->next;
		}
		if (io_file_input(all, process, list->content) == -1)
			return (-2);
	}
	return (0);
}
