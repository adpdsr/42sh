/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hack_space.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwells <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/02 15:32:41 by gwells            #+#    #+#             */
/*   Updated: 2016/09/04 16:30:56 by fviolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lineedit.h"

void	recover_space(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == 127)
			line[i] = ' ';
		i++;
	}
}

void	supress_bslash_space(t_inhib *line)
{
	int		i;

	i = 0;
	while (line[i].c)
	{
		if (line[i].c == ' ' && bslash_before(line, i))
			line[i].c = 127;
		i++;
	}
}
