/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwells <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/24 13:58:48 by gwells            #+#    #+#             */
/*   Updated: 2016/09/08 17:19:08 by adu-pelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"
#include "lineedit.h"

void				sig_clear(int sig)
{
	t_signal_var	*s;
	t_cursor		tmp;

	(void)sig;
	s = singleton();
	buffer_to_cursor(ft_strlen(s->input->cmd_line)\
	+ s->input->sprompt, &tmp);
	while (tmp.y - s->input->cursor->y >= 0)
	{
		ft_putchar('\n');
		tmp.y--;
	}
	prompt(s->env);
	s->input->cursor->x = s->input->sprompt;
	s->input->cursor->y = 0;
	free(s->input->cmd_line);
	s->input->cmd_line = ft_strdup("");
}

static void			sig_kill(int sig)
{
	int				singletone;

	singletone = *pid();
	if (singletone > 0)
	{
		ft_putendl("");
		kill(singletone, sig);
		exit_term();
	}
}

static void			sig_nothing(int sig)
{
	(void)sig;
	return ;
}

void				set_signal(void)
{
	signal(SIGTSTP, sig_nothing);
	signal(SIGQUIT, sig_nothing);
	signal(SIGINT, sig_nothing);
	signal(SIGTERM, sig_nothing);
}

void				restore_signal(void)
{
	signal(SIGTSTP, SIG_DFL);
	signal(SIGINT, sig_kill);
}
