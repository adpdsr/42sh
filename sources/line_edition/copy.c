/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adu-pelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/25 09:10:21 by adu-pelo          #+#    #+#             */
/*   Updated: 2016/07/25 09:10:22 by adu-pelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lineedit.h"

static void			nputchar(int len)
{
	int				i;
	t_signal_var	*s;

	s = singleton();
	i = 0;
	while (i++ != len)
	{
		ft_putchar(s->input->cmd_line[cursor_to_sbuffer(s->input->cursor->x, \
		s->input->cursor->y) - s->input->sprompt]);
		putchar_move_cursor(s->input->cursor);
	}
}

static void			move_n_left(int len, t_event *event)
{
	int				i;

	i = 0;
	while (i++ != len)
		move_left(event);
}

void				copy(t_event *event, t_cursor cur)
{
	int				pos;
	int				pos_cur;
	t_signal_var	*s;

	s = singleton();
	pos_cur = cursor_to_sbuffer(s->input->cursor->x, s->input->cursor->y);
	pos = cursor_to_sbuffer(cur.x, cur.y);
	split_cmd_line(pos_cur, pos);
	if (pos_cur > pos)
	{
		move_n_left(pos_cur - pos, event);
		nputchar(pos_cur - pos);
	}
	else
		nputchar(ft_abs(pos_cur - pos) + 1);
}
