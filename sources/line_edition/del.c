/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adu-pelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/25 09:10:35 by adu-pelo          #+#    #+#             */
/*   Updated: 2016/07/25 09:10:36 by adu-pelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lineedit.h"

static void			del_rec(int y, char *buffer, int rec)
{
	int				len;
	t_signal_var	*s;

	s = singleton();
	len = ft_strlen(buffer) + s->input->sprompt;
	if (y < len / (s->ws.ws_col + 1))
	{
		use_cap("sc");
		use_ncap("do", rec);
		use_cap("dc");
		use_cap("up");
		use_cap("cr");
		use_ncap("nd", s->ws.ws_col + 1);
		ft_putchar(buffer[cursor_to_sbuffer(0, y + 1) - s->input->sprompt - 1]);
		use_cap("rc");
		del_rec(y + 1, buffer, rec + 1);
	}
}

static void			del_end_of_line(char *cmd_line)
{
	t_signal_var	*s;

	s = singleton();
	s->input->cursor->y--;
	s->input->cursor->x = s->ws.ws_col;
	use_cap("up");
	use_ncap("nd", s->ws.ws_col - 1);
	if (check_max(s->input->cursor, cmd_line, 0))
		supress_end();
}

static void			del_basic(void)
{
	t_signal_var	*s;

	s = singleton();
	s->input->cursor->x--;
	use_cap("le");
	use_cap("dc");
}

void				del(void)
{
	char			*tmp;
	t_signal_var	*s;

	s = singleton();
	if (ft_strlen(s->input->cmd_line) == 0 || \
		check_max(s->input->cursor, s->input->cmd_line, 0))
		return ;
	tmp = ft_strsupress_at(s->input->cmd_line,\
	cursor_to_sbuffer(s->input->cursor->x, s->input->cursor->y)\
		- s->input->sprompt);
	free(s->input->cmd_line);
	if (s->input->cursor->x == s->ws.ws_col)
		supress_end();
	else
		use_cap("dc");
	if (line_full(ft_strlen(tmp) + s->input->sprompt,\
		s->input->cursor->y, s->input->sprompt))
		del_rec(s->input->cursor->y, tmp, 0);
	s->input->cmd_line = tmp;
}

void				del_at(void)
{
	char			*tmp;
	t_signal_var	*s;

	s = singleton();
	if (s->input->cursor->x - 1 < s->input->sprompt && s->input->cursor->y == 0)
		return ;
	tmp = ft_strsupress_at(s->input->cmd_line,\
	cursor_to_sbuffer(s->input->cursor->x, s->input->cursor->y)\
		- s->input->sprompt - 1);
	free(s->input->cmd_line);
	if (s->input->cursor->x - 1 < 0)
		del_end_of_line(tmp);
	else
		del_basic();
	if (line_full(ft_strlen(tmp) + s->input->sprompt,\
		s->input->cursor->y, s->input->sprompt))
		del_rec(s->input->cursor->y, tmp, 0);
	s->input->cmd_line = tmp;
}
