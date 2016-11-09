/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adu-pelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/25 09:12:31 by adu-pelo          #+#    #+#             */
/*   Updated: 2016/07/25 09:12:32 by adu-pelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lineedit.h"

static void			so_or_not(int pos, t_cursor *cursor, int left_right)
{
	int				len;

	len = cursor_to_sbuffer(cursor->x, cursor->y) - left_right;
	if (len < pos)
	{
		if (len - left_right < len)
			use_cap("so");
		else
			use_cap("se");
	}
	if (len > pos)
	{
		if (len - left_right > len)
			use_cap("so");
		else
			use_cap("se");
	}
}

static int			init(t_event *event, t_cursor *cp)
{
	int				pos;
	t_signal_var	*s;

	s = singleton();
	use_cap("ei");
	if (check_max(s->input->cursor, s->input->cmd_line, 0))
		move_left(event);
	cp->x = s->input->cursor->x;
	cp->y = s->input->cursor->y;
	pos = cursor_to_sbuffer(s->input->cursor->x, s->input->cursor->y);
	use_cap("so");
	ft_putchar(s->input->cmd_line[pos - s->input->sprompt]);
	if (s->input->cursor->x == s->ws.ws_col)
		use_ncap("nd", s->ws.ws_col - 1);
	else
		use_cap("le");
	use_cap("se");
	return (pos);
}

static void			while2(t_event *event, int pos)
{
	int				i;
	t_signal_var	*s;

	s = singleton();
	ft_memset(event->buffer, '\0', 7);
	read(0, event->buffer, 7);
	i = 0;
	while (i != WHILE2)
	{
		if (!ft_memcmp(event->buffer, (void*)&(event->cmove[i]), sizeof(int)))
		{
			if (i == CLEFT)
				so_or_not(pos, s->input->cursor, 1);
			else
				so_or_not(pos, s->input->cursor, -1);
			(*(event->w2ptrfunc)[i])(event);
		}
		i++;
	}
}

static int			cut_or_cp(t_event *event, t_cursor cp)
{
	if ((*(int*)event->buffer) == T_CUT)
	{
		use_cap("se");
		cut(event, cp);
		return (1);
	}
	else if ((*(int*)event->buffer) == T_CP)
	{
		use_cap("se");
		copy(event, cp);
		return (1);
	}
	return (0);
}

void				select_c(t_event *event)
{
	t_signal_var	*s;
	t_cursor		cp;
	int				pos;

	s = singleton();
	if (ft_strlen(s->input->cmd_line) == 0)
		return ;
	pos = init(event, &cp);
	while (42)
	{
		while2(event, pos);
		if (cut_or_cp(event, cp) == 1)
			break ;
	}
	use_cap("se");
	use_cap("im");
}
