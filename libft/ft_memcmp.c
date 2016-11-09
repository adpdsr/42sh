/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwells <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 22:21:18 by gwells            #+#    #+#             */
/*   Updated: 2014/11/13 20:05:33 by gwells           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;
	size_t			count;

	str1 = (unsigned char*)s1;
	str2 = (unsigned char*)s2;
	count = 0;
	if (n == 0)
		return (0);
	while (count < n)
	{
		if (str1[count] != str2[count])
			return ((int)(str1[count] - str2[count]));
		count++;
	}
	return (0);
}
