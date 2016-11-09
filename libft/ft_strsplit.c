/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwells <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 16:43:27 by gwells            #+#    #+#             */
/*   Updated: 2015/05/06 15:34:58 by gwells           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char		**ft_strsplit(char const *s, char c)
{
	char	**str;
	int		index;
	int		len;
	int		i;

	if (s)
	{
		index = 0;
		len = 0;
		i = 0;
		str = (char **)ft_memalloc_fail(sizeof(char *) * (words(s, c) + 1));
		while (s[len] && s[index])
		{
			while (s[index] && s[index] == c)
				index++;
			len = index;
			while (s[len] && s[len] != c)
				len++;
			str[i++] = ft_strsub(s, index, len - index);
			index = len;
		}
		str[words(s, c)] = 0;
		return (str);
	}
	return (NULL);
}
