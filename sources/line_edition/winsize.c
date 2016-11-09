/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   winsize.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwells <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/24 13:56:45 by gwells            #+#    #+#             */
/*   Updated: 2016/09/08 20:02:31 by adu-pelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lineedit.h"

void				get_winsize(void)
{
	t_signal_var	*s;
	int				pos;
	static int		i = 0;

	s = singleton();
	if (ioctl(s->fd, TIOCGWINSZ, &s->ws) == -1)
		ft_quit("Ioctl error", 2, -1);
	s->ws.ws_col--;
	s->ws.ws_row--;
	pos = cursor_to_sbuffer(s->input->cursor->x, s->input->cursor->y)\
	- s->input->sprompt;
	buffer_to_cursor(pos + s->input->sprompt, s->input->cursor);
	if (i >= 1)
	{
		use_cap("cl");
		prompt(s->env);
		print_line();
	}
	i = 1;
}

int					cursor_to_sbuffer(int x, int y)
{
	t_signal_var	*s;

	s = singleton();
	return (x + y * (s->ws.ws_col + 1));
}

void				buffer_to_cursor(int pos, t_cursor *cursor)
{
	t_signal_var	*s;

	s = singleton();
	cursor->y = pos / (s->ws.ws_col + 1);
	cursor->x = pos % (s->ws.ws_col + 1);
}

int					line_full(int len, int y, int prompt_size)
{
	int				nlen;
	t_signal_var	*s;

	s = singleton();
	nlen = s->ws.ws_col + y * (s->ws.ws_col + 1);
	nlen -= prompt_size;
	if (len > nlen)
		return (1);
	return (0);
}
