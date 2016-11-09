/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   home_end.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adu-pelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/25 09:11:10 by adu-pelo          #+#    #+#             */
/*   Updated: 2016/07/25 09:11:12 by adu-pelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lineedit.h"

void				home(void)
{
	t_signal_var	*s;

	s = singleton();
	use_ncap("up", s->input->cursor->y - 1);
	use_cap("cr");
	use_ncap("nd", s->input->sprompt - 1);
	s->input->cursor->x = s->input->sprompt;
	s->input->cursor->y = 0;
}

void				end(void)
{
	t_cursor		new_cur;
	t_signal_var	*s;

	s = singleton();
	buffer_to_cursor(ft_strlen(s->input->cmd_line)\
	+ s->input->sprompt, &new_cur);
	use_cap("cr");
	use_ncap("do", new_cur.y - 1 - s->input->cursor->y);
	use_ncap("nd", new_cur.x - 1);
	s->input->cursor->x = new_cur.x;
	s->input->cursor->y = new_cur.y;
}
