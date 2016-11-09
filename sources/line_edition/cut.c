/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cut.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adu-pelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/25 09:10:28 by adu-pelo          #+#    #+#             */
/*   Updated: 2016/07/25 09:10:29 by adu-pelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lineedit.h"

static void			supress_zone(int nb, t_event *event)
{
	int				i;

	i = 0;
	del(event);
	while (i++ != nb)
		del_at(event);
}

static void			move_n_right(int nb, t_event *event)
{
	int				i;

	i = 0;
	while (i++ != nb)
		move_right(event);
}

void				cut(t_event *event, t_cursor cur)
{
	int				pos_cur;
	int				pos;
	t_signal_var	*s;

	s = singleton();
	pos_cur = cursor_to_sbuffer(s->input->cursor->x, s->input->cursor->y);
	pos = cursor_to_sbuffer(cur.x, cur.y);
	split_cmd_line(pos_cur, pos);
	if (pos_cur > pos)
		supress_zone(pos_cur - pos, event);
	else if (pos_cur < pos)
	{
		move_n_right(ft_abs(pos_cur - pos), event);
		supress_zone(ft_abs(pos_cur - pos), event);
	}
	else
		del(event);
}
