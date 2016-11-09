/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers_lexer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fviolin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/07 12:07:53 by fviolin           #+#    #+#             */
/*   Updated: 2016/09/08 19:34:17 by adu-pelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

int		is_active_token(t_inhib *line, int start, int len)
{
	int	i;

	i = 0;
	while (i != len)
	{
		if (line[start].active && line[start].c != '\"'\
				&& line[start].c != '\'' && line[start].c != '$' &&\
				line[start].c != '\\')
			return (1);
		start++;
		i++;
	}
	return (0);
}
