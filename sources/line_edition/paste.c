/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paste.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fviolin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/28 16:46:15 by fviolin           #+#    #+#             */
/*   Updated: 2016/07/28 17:01:17 by fviolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lineedit.h"

void				past(void)
{
	int				i;
	t_signal_var	*s;
	int				len;
	char			*tmp;

	i = 0;
	s = singleton();
	len = ft_strlen(s->input->cp) + ft_strlen(s->input->cmd_line);
	while (s->input->cp && s->input->cp[i] && len < 600)
	{
		insert_rec(s->input->cursor->y, s->input->cmd_line, 0);
		tmp = ft_strinsert_at(s->input->cmd_line,\
		s->input->cp[i], cursor_to_sbuffer(s->input->cursor->x,\
		s->input->cursor->y) - s->input->sprompt);
		free(s->input->cmd_line);
		s->input->cmd_line = tmp;
		ft_putchar(s->input->cp[i]);
		putchar_move_cursor(s->input->cursor);
		i++;
	}
}
