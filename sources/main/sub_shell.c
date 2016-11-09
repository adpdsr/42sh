/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_shell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fviolin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/07 19:05:55 by fviolin           #+#    #+#             */
/*   Updated: 2016/09/08 15:43:55 by gwells           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lineedit.h>
#include <sh.h>

void			launch_sub_prompt(t_event *event, t_all *all, char **gnl)
{
	t_signal_var	*s;
	char			*tmp;

	s = singleton();
	free(s->line);
	ft_putstr("$>  ");
	s->input->sprompt = 4;
	buffer_to_cursor(s->input->sprompt, s->input->cursor);
	ft_strdel(&s->input->cmd_line);
	s->line = newline_append2(*gnl);
	ft_strdel(gnl);
	*gnl = save_str(s->line);
	ft_strdel(&s->input->cmd_line);
	s->input->cmd_line = ft_strdup("");
	line_edition(event, all, 1);
	tmp = *gnl;
	*gnl = ft_strjoin(*gnl, s->input->cmd_line);
	free(tmp);
	free(s->line);
	s->line = init_inhib_line(*gnl);
	active_quotes(s->line);
	active_bslash(s->line);
	end();
}
