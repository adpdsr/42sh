/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_select.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adu-pelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/25 09:12:08 by adu-pelo          #+#    #+#             */
/*   Updated: 2016/07/25 09:12:09 by adu-pelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lineedit.h"

void		smove_left(void)
{
	t_signal_var *s;

	s = singleton();
	if (s->input->cursor->x - 1 < s->input->sprompt && s->input->cursor->y == 0)
		return ;
	ft_putchar(s->input->cmd_line[cursor_to_sbuffer(s->input->cursor->x,\
	s->input->cursor->y) - s->input->sprompt]);
	if (s->input->cursor->x - 1 < 0)
	{
		s->input->cursor->y--;
		s->input->cursor->x = s->ws.ws_col;
		use_cap("up");
		use_ncap("nd", s->ws.ws_col - 1);
	}
	else
	{
		use_cap("le");
		if (s->input->cursor->x != s->ws.ws_col)
			use_cap("le");
		s->input->cursor->x--;
	}
}

void		smove_right(void)
{
	t_signal_var *s;

	s = singleton();
	if (cursor_to_sbuffer(s->input->cursor->x + 1, s->input->cursor->y) > \
			(int)ft_strlen(s->input->cmd_line) + s->input->sprompt - 1)
		return ;
	ft_putchar(s->input->cmd_line[cursor_to_sbuffer(s->input->cursor->x, \
				s->input->cursor->y) - s->input->sprompt]);
	if (s->input->cursor->x + 1 <= s->ws.ws_col)
		s->input->cursor->x++;
	else
	{
		s->input->cursor->y++;
		s->input->cursor->x = 0;
		use_cap("cr");
		use_cap("do");
	}
}
