/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers_strsplit.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fviolin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/04 17:02:36 by fviolin           #+#    #+#             */
/*   Updated: 2016/09/04 17:07:41 by fviolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>
#include <lineedit.h>

int		check_semicolon(t_inhib *line)
{
	int i;

	i = 0;
	while (line[i].c)
	{
		if (line[i].c == ';' && line[i].active && line[i + 1].c\
				&& line[i + 1].c == ';' && line[i + 1].active)
			return (0);
		i++;
	}
	return (1);
}

int		count_semicolon_active(t_inhib *line)
{
	int i;
	int count;

	i = 0;
	count = 1;
	i++;
	while (line[i].c)
	{
		if (line[i].c == ';' && line[i].active &&\
				line[i + 1].c != '\0')
			count++;
		i++;
	}
	return (count);
}
