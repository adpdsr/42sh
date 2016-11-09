/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fword_bword.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fviolin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/28 16:42:15 by fviolin           #+#    #+#             */
/*   Updated: 2016/09/09 10:04:24 by gwells           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lineedit.h"

static void			move_fword(t_cursor new_cur, t_cursor *cursor)
{
	use_cap("cr");
	use_ncap("do", new_cur.y - cursor->y - 1);
	use_ncap("nd", new_cur.x - 1);
	cursor->x = new_cur.x;
	cursor->y = new_cur.y;
}

void				fword(void)
{
	char			*pos;
	char			*new_pos;
	int				len;
	t_cursor		new_cur;
	t_signal_var	*s;

	s = singleton();
	len = cursor_to_sbuffer(s->input->cursor->x, s->input->cursor->y)\
	- s->input->sprompt;
	pos = &s->input->cmd_line[len];
	new_pos = ft_strpbrk(pos, "\t ");
	if (new_pos == NULL)
	{
		end();
		return ;
	}
	while (*new_pos && (*new_pos == '\t' || *new_pos == ' '))
		new_pos++;
	len += new_pos - pos;
	buffer_to_cursor(len + s->input->sprompt, &new_cur);
	move_fword(new_cur, s->input->cursor);
}

static void			move_bword(t_cursor new_cur, t_cursor *cursor)
{
	use_cap("cr");
	use_ncap("up", cursor->y - new_cur.y - 1);
	use_ncap("nd", new_cur.x - 1);
	cursor->x = new_cur.x;
	cursor->y = new_cur.y;
}

void				bword(void)
{
	char			*cp;
	int				len;
	char			*new_pos;
	t_cursor		new_cur;
	t_signal_var	*s;

	s = singleton();
	len = cursor_to_sbuffer(s->input->cursor->x,\
	s->input->cursor->y) - s->input->sprompt;
	while (len >= 1 && (s->input->cmd_line[len - 1] == '\t'\
	|| s->input->cmd_line[len - 1] == ' '))
		len--;
	cp = ft_strsub(s->input->cmd_line, 0, len);
	new_pos = ft_strrpbrk(cp, "\t ");
	buffer_to_cursor(len - (&cp[len] - new_pos) + s->input->sprompt, &new_cur);
	move_bword(new_cur, s->input->cursor);
	free(cp);
}
