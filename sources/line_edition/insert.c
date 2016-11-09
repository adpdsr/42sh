/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adu-pelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/25 09:11:27 by adu-pelo          #+#    #+#             */
/*   Updated: 2016/09/06 18:30:02 by gwells           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lineedit.h"

void				insert_rec(int y, char *buffer, int rec)
{
	t_signal_var	*s;

	s = singleton();
	if (line_full(ft_strlen(buffer), y, s->input->sprompt))
	{
		use_ncap("do", rec);
		ft_putchar(buffer[cursor_to_sbuffer(s->ws.ws_col, y)\
		- s->input->sprompt]);
		use_ncap("up", rec);
		use_cap("cr");
		use_ncap("nd", s->input->cursor->x - 1);
		insert_rec(y + 1, buffer, rec + 1);
	}
}

char				*insert_at(char *buffer, char c)
{
	t_signal_var	*s;

	s = singleton();
	insert_rec(s->input->cursor->y, buffer, 0);
	buffer = ft_strinsert_at(buffer, c, cursor_to_sbuffer(s->input->cursor->x,\
	s->input->cursor->y) - s->input->sprompt);
	ft_putchar(c);
	putchar_move_cursor(s->input->cursor);
	return (buffer);
}
