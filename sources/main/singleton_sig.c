/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   singleton_sig.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwells <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/24 13:58:56 by gwells            #+#    #+#             */
/*   Updated: 2016/09/08 16:56:13 by adu-pelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"
#include "lineedit.h"

int							*pid(void)
{
	static int				pid;

	return (&pid);
}

t_signal_var				*singleton(void)
{
	static	t_signal_var	singleton;

	return (&singleton);
}

void						sig_win_size(void)
{
	t_signal_var			*s;

	s = singleton();
	get_winsize(s->fd);
}

void						sig_term(int sig)
{
	(void)sig;
	use_cap("ei");
	use_cap("ke");
	exit_term();
	exit(130);
}
