/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fviolin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/28 16:44:16 by fviolin           #+#    #+#             */
/*   Updated: 2016/07/28 16:45:00 by fviolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lineedit.h"

static void		free_history(t_his **head)
{
	t_his	*next;

	while (*head)
	{
		next = (*head)->next;
		ft_strdel(&((*head)->cmd));
		free(*head);
		*head = next;
	}
}

void			free_singleton(void)
{
	t_signal_var	*s;

	s = singleton();
	free(s->abs_path);
	free(s->input->cmd_line);
	free(s->input->cursor);
	if (s->input->cp != NULL)
		free(s->input->cp);
	free_history(&s->input->history);
	free(s->input);
}
