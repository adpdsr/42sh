/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers_io_files.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adu-pelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/25 09:13:10 by adu-pelo          #+#    #+#             */
/*   Updated: 2016/09/04 18:41:27 by fviolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>
#include <processes.h>
#include <lineedit.h>

void	open_file_for_redir(t_all *all, t_lexer *lex)
{
	t_signal_var	*s;
	int				o_flag;

	s = singleton();
	o_flag = O_CREAT | O_WRONLY;
	if (lex->token == GREAT)
		o_flag |= O_TRUNC;
	else if (lex->token == DGREAT)
		o_flag |= O_APPEND;
	if (lex->next->cmd[0])
	{
		if ((all->exec->fd_write = open(lex->next->cmd[0], o_flag, 0644)) == -1)
		{
			ft_putendl_fd("42sh: permission denied", 2);
			s->ret = 1;
		}
		else
			s->ret = 0;
	}
}

int		count_fd_digit_len(char *str, int i)
{
	int len;

	len = 0;
	while (ft_isdigit(str[i]))
	{
		i++;
		len++;
	}
	return (len);
}
