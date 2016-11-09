/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_inhib.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fviolin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/28 15:43:48 by fviolin           #+#    #+#             */
/*   Updated: 2016/09/04 16:29:15 by fviolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lineedit.h"

static int		count_last_bslash(char *str, int len)
{
	int				count;

	count = 0;
	while (len > 0 && str[len - 1] == '\\')
	{
		count++;
		len--;
	}
	return (count);
}

int				check_inhib_bslash(char *tmp, int mode)
{
	int i;

	i = 0;
	while (tmp[i])
		i++;
	if (!mode)
		if (i > 1 && !tmp[i] && tmp[i - 2] == '\\' && tmp[i - 1] == '\n')
			return (BSLASH);
	if (mode)
		if (i > 0 && !tmp[i] && tmp[i - 1] == '\\' &&\
			!(count_last_bslash(tmp, i - 1) % 2))
			return (BSLASH);
	return (0);
}

int				check_inhib(t_inhib *line)
{
	int i;

	i = 0;
	while (line[i].c)
	{
		if (line[i].c == '\"' && line[i].active)
			if (!read_inhib(line, &i, '\"'))
				return (FTDQUOTE);
		if (line[i].c == '\'' && line[i].active)
			if (!read_inhib(line, &i, '\''))
				return (SQUOTE);
		i++;
	}
	return (0);
}
