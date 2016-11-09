/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_edit_tools.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adu-pelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/25 09:11:45 by adu-pelo          #+#    #+#             */
/*   Updated: 2016/07/25 09:11:46 by adu-pelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lineedit.h"

void				use_ncap(char *cap, int n)
{
	char			*res;
	int				i;

	i = 0;
	while (i <= n)
	{
		if ((res = tgetstr(cap, NULL)) == NULL)
			ft_quit("The cap doesn't exist\n", 2, -1);
		ft_putstr(res);
		i++;
	}
}

void				use_cap(char *cap)
{
	char			*res;

	if ((res = tgetstr(cap, NULL)) == NULL)
		ft_quit("The cap doesn't exist\n", 2, -1);
	ft_putstr(res);
}

char				*fetch_cap(char *cap)
{
	char			*ret;

	if ((ret = tgetstr(cap, NULL)) == NULL)
		ft_quit("The cap doesn't exist\n", 2, -1);
	return (ret);
}

void				putchar_move_cursor(void)
{
	t_signal_var	*s;

	s = singleton();
	if (s->input->cursor->x + 1 <= s->ws.ws_col)
		s->input->cursor->x++;
	else
	{
		use_cap("do");
		use_cap("cr");
		s->input->cursor->x = 0;
		s->input->cursor->y++;
	}
}

int					check_max(t_cursor *cursor, char *cmd_line, int index)
{
	t_signal_var	*s;

	s = singleton();
	if ((cursor_to_sbuffer(cursor->x, cursor->y) - \
		s->input->sprompt + index) == (int)ft_strlen(cmd_line))
		return (1);
	else
		return (0);
}
