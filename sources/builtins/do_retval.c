/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_retval.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adu-pelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/23 21:45:54 by adu-pelo          #+#    #+#             */
/*   Updated: 2016/09/09 09:46:37 by fviolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>
#include <builtins.h>

int		check_status(int status)
{
	t_signal_var *s;

	s = singleton();
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	else if (WIFSIGNALED(status))
	{
		if (WTERMSIG(status) == 15)
			return (130);
		return (129);
	}
	return (0);
}

char	*do_retval(char **str)
{
	t_signal_var	*s;
	char			*val;

	s = singleton();
	*str += 2;
	val = ft_itoa(s->ret);
	s->ret = 0;
	return (val);
}
