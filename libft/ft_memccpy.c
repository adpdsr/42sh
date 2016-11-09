/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwells <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 18:18:33 by gwells            #+#    #+#             */
/*   Updated: 2014/11/13 16:25:58 by gwells           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*s1;
	unsigned char	*s2;
	unsigned char	ch;
	size_t			count;

	s1 = (unsigned char *)dst;
	s2 = (unsigned char *)src;
	ch = (unsigned char)c;
	count = 0;
	while (count < n)
	{
		*s1 = *s2;
		if (*s1 == ch)
			return ((void*)(s1 + 1));
		s1++;
		s2++;
		count++;
	}
	return (NULL);
}
