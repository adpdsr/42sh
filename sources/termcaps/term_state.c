/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term_state.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fviolin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/28 16:48:37 by fviolin           #+#    #+#             */
/*   Updated: 2016/09/08 20:43:05 by fviolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"
#include "lineedit.h"

void		init_term_suite(void)
{
	t_signal_var	*s;

	s = singleton();
	s->term->termios.c_lflag &= ~(ICANON);
	s->term->termios.c_lflag &= ~(ECHO);
	s->term->termios.c_cc[VMIN] = 1;
	s->term->termios.c_cc[VTIME] = 0;
	if (tcsetattr(s->term->fd, TCSANOW, &(s->term->termios)) == -1)
		ft_error("error: tcsetattr", 1);
}

t_term		*init_term(void)
{
	char			*name;
	t_signal_var	*s;

	s = singleton();
	name = NULL;
	if (s->ret == 130)
	{
		use_cap("ei");
		use_cap("ke");
		exit_term();
		exit(130);
	}
	if (!isatty(0))
		ft_error("error: isatty", 1);
	s->term = ft_memalloc_fail(sizeof(t_term));
	if ((s->term->fd = open(ttyname(0), O_RDWR)) == -1)
		ft_error("error: tyyname", 1);
	ft_strdel(&name);
	if (tgetent(NULL, getenv("TERM")) < 1)
		ft_error("error: tgetent", 1);
	if (tcgetattr(s->term->fd, &(s->term->termios)) == -1)
		ft_error("error: tcgetattr", 1);
	init_term_suite();
	return (s->term);
}

void		exit_term(void)
{
	t_signal_var *s;

	s = singleton();
	if (tcgetattr(s->term->fd, &s->term->termios) == -1)
		ft_error("error: tcgetattr", 0);
	s->term->termios.c_lflag |= (ICANON | ECHO);
	if (tcsetattr(s->term->fd, TCSANOW, &(s->term->termios)) == -1)
		ft_error("error: tcsetattr", 0);
	close(s->term->fd);
	if (s->ret != 130)
		free(s->term);
}
