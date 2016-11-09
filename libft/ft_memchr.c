/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwells <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 21:45:39 by gwells            #+#    #+#             */
/*   Updated: 2014/12/25 16:02:50 by gwells           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	unsigned char	ch;
	size_t			count;

	str = (unsigned char *)s;
	ch = (unsigned char)c;
	count = 0;
	if (!str)
		return (NULL);
	while (count < n)
	{
		if (*str == ch)
			return (str);
		str++;
		count++;
	}
	return (NULL);
}
