/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwells <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/12 08:28:16 by gwells            #+#    #+#             */
/*   Updated: 2015/02/12 09:17:20 by gwells           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char			*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t		i;
	size_t		j;
	size_t		temp;

	i = 0;
	j = 0;
	if (!*s2)
		return ((char*)s1);
	while (s1[i] && i < n)
	{
		temp = i;
		while (s1[i] && s2[j] && i < n && s1[i] == s2[j])
		{
			i++;
			j++;
		}
		if (!s2[j])
			return ((char*)&s1[temp]);
		else
			j = 0;
		i = temp + 1;
	}
	return (NULL);
}
