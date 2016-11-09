/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adu-pelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/25 09:12:38 by adu-pelo          #+#    #+#             */
/*   Updated: 2016/07/25 09:12:39 by adu-pelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lineedit.h"

void				supress_end(void)
{
	t_signal_var	*s;

	s = singleton();
	ft_putchar(' ');
	use_ncap("nd", s->ws.ws_col - 1);
}

void				split_cmd_line(int pos_cur, int pos)
{
	char			*tmp;
	t_signal_var	*s;

	s = singleton();
	tmp = ft_memalloc_fail(sizeof(char) * (ft_abs(pos_cur - pos) + 10));
	if (pos_cur > pos)
		tmp = ft_strncpy(tmp, &(s->input->cmd_line[pos - \
		s->input->sprompt]), pos_cur - pos + 1);
	else if (pos_cur < pos)
		tmp = ft_strncpy(tmp, &(s->input->cmd_line[pos_cur -\
		s->input->sprompt]), ft_abs(pos_cur - pos) + 1);
	else
		tmp[0] = s->input->cmd_line[pos_cur - s->input->sprompt];
	tmp[ft_abs(pos_cur - pos) + 1] = '\0';
	s->input->cp = tmp;
}
