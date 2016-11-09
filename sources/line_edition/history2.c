/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adu-pelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/25 09:11:04 by adu-pelo          #+#    #+#             */
/*   Updated: 2016/09/08 20:02:25 by adu-pelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lineedit.h>

void	h_insert(void)
{
	t_signal_var	*s;
	char			*translated;

	s = singleton();
	translated = translate_excla(s->input->cmd_line, NULL, NULL);
	insert_in_history(&(s->input->history), translated);
	ft_strdel(&translated);
}

void	supress_line(void)
{
	t_signal_var *s;

	s = singleton();
	use_cap("cr");
	use_ncap("up", s->input->cursor->y - 1);
	use_cap("cd");
}

void	print_line(void)
{
	t_signal_var *s;

	s = singleton();
	ft_putstr(s->input->cmd_line);
	buffer_to_cursor(ft_strlen(s->input->cmd_line) +\
	s->input->sprompt, s->input->cursor);
	if (ft_cntc(s->input->cmd_line, '\n'))
		s->input->cursor->y += ft_cntc(s->input->cmd_line, '\n');
	else
	{
		buffer_to_cursor(ft_strlen(s->input->cmd_line) +\
		s->input->sprompt, s->input->cursor);
	}
}

void	history_up(void)
{
	t_signal_var *s;

	s = singleton();
	if (s->input->history)
	{
		if (s->input->is_h == 0)
		{
			set_history(s->input->history, s->input->cmd_line);
			s->input->is_h = 1;
		}
		else
			select_history_up(s->input->history);
		buffer_to_cursor(ft_strlen(s->input->cmd_line) +\
		s->input->sprompt, s->input->cursor);
		if (ft_cntc(s->input->cmd_line, '\n'))
			s->input->cursor->y += ft_cntc(s->input->cmd_line, '\n');
		free(s->input->cmd_line);
		s->input->cmd_line = ft_strdup(get_history_line(&(s->input->history),\
					s->input->cmd_line));
		supress_line();
		prompt(s->env);
		print_line();
	}
}

void	history_down(void)
{
	t_signal_var *s;

	s = singleton();
	if (s->input->history)
	{
		if (s->input->is_h == 0)
		{
			set_history(s->input->history, s->input->cmd_line);
			s->input->is_h = 1;
		}
		else
			select_history_down(s->input->history);
		buffer_to_cursor(ft_strlen(s->input->cmd_line) +\
		s->input->sprompt, s->input->cursor);
		if (ft_cntc(s->input->cmd_line, '\n'))
			s->input->cursor->y += ft_cntc(s->input->cmd_line, '\n');
		free(s->input->cmd_line);
		s->input->cmd_line = ft_strdup(get_history_line(&(s->input->history),\
					s->input->cmd_line));
		supress_line();
		prompt(s->env);
		print_line();
	}
}
