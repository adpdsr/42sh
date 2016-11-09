/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_union.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwells <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/16 13:02:29 by gwells            #+#    #+#             */
/*   Updated: 2015/03/09 11:30:58 by gwells           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

static int			count_or_place(char *argv, size_t *pos, char *str, int func)
{
	int					i;
	static size_t		place = 0;

	i = *pos;
	while (i >= 0)
	{
		if (i >= 1 && argv[i - 1] == argv[*pos])
		{
			(*pos)++;
			return (0);
		}
		i--;
	}
	if (!func)
	{
		str[place] = argv[*pos];
		place++;
	}
	(*pos)++;
	if (*pos == ft_strlen(argv))
		place = 0;
	return (1);
}

char				*ft_union(char *argv)
{
	size_t				size;
	size_t				pos;
	size_t				mem;
	char				*str;

	pos = 0;
	mem = 0;
	str = NULL;
	if (argv)
	{
		size = ft_strlen(argv);
		while (pos < size)
			mem += count_or_place(argv, &pos, str, 1);
		pos = 0;
		str = ft_strnew(mem);
		while (pos < size)
			count_or_place(argv, &pos, str, 0);
	}
	return (str);
}
