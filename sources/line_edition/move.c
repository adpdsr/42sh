/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adu-pelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/25 09:12:00 by adu-pelo          #+#    #+#             */
/*   Updated: 2016/07/25 09:12:01 by adu-pelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lineedit.h"

void				move_left(void)
{
	t_signal_var	*s;

	s = singleton();
	if (s->input->cursor->x - 1 < s->input->sprompt && s->input->cursor->y == 0)
		return ;
	if (s->input->cursor->x - 1 < 0)
	{
		s->input->cursor->y--;
		s->input->cursor->x = s->ws.ws_col;
		use_cap("up");
		use_ncap("nd", s->ws.ws_col);
	}
	else
	{
		s->input->cursor->x--;
		use_cap("le");
	}
}

void				move_right(void)
{
	t_signal_var	*s;

	s = singleton();
	if (cursor_to_sbuffer(s->input->cursor->x + 1, s->input->cursor->y) > \
			(int)ft_strlen(s->input->cmd_line) + s->input->sprompt)
		return ;
	if (s->input->cursor->x + 1 <= s->ws.ws_col)
	{
		s->input->cursor->x++;
		use_cap("nd");
	}
	else
	{
		s->input->cursor->y++;
		s->input->cursor->x = 0;
		use_cap("cr");
		use_cap("do");
		if (s->input->cursor->y == 0)
		{
			s->input->cursor->x = s->input->sprompt;
			use_ncap("nd", s->input->cursor->x);
		}
	}
}

void				move_down(void)
{
	size_t			len;
	t_signal_var	*s;

	s = singleton();
	len = ft_strlen(s->input->cmd_line) + s->input->sprompt;
	if (cursor_to_sbuffer(s->input->cursor->x,\
	s->input->cursor->y + 1) < (int)len)
	{
		s->input->cursor->y++;
		use_cap("do");
		use_ncap("nd", s->input->cursor->x - 1);
	}
	else
	{
		if (s->input->cursor->y + 1 == (int)(len - 1) / (s->ws.ws_col + 1))
		{
			use_cap("do");
			use_cap("cr");
			s->input->cursor->y++;
			use_ncap("nd", (len - 1) % (s->ws.ws_col + 1));
			s->input->cursor->x = (len - 1) % (s->ws.ws_col + 1) + 1;
		}
	}
}

void				move_up(void)
{
	t_signal_var	*s;

	s = singleton();
	if (s->input->cursor->y - 1 >= 0)
	{
		use_cap("up");
		s->input->cursor->y--;
	}
	if (s->input->cursor->x <= s->input->sprompt && s->input->cursor->y == 0)
	{
		s->input->cursor->x = 0;
		use_cap("cr");
		use_ncap("nd", s->input->sprompt - 1);
		s->input->cursor->x = s->input->sprompt;
	}
}
