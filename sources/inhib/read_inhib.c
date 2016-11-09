/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_inhib.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fviolin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/28 15:45:40 by fviolin           #+#    #+#             */
/*   Updated: 2016/09/04 14:13:28 by fviolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lineedit.h>

int	read_inhib(t_inhib *line, int *i, char c)
{
	(*i)++;
	while (line[*i].c && (line[*i].c != c || !line[*i].active))
		(*i)++;
	if (line[*i].c == c && line[*i].active)
		return (1);
	else
		return (0);
}
