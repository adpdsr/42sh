/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwells <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 13:00:09 by gwells            #+#    #+#             */
/*   Updated: 2014/11/13 16:43:14 by gwells           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strncat(char *dst, const char *src, size_t n)
{
	size_t	count;
	size_t	count2;

	count = 0;
	count2 = 0;
	while (dst[count] != '\0')
	{
		count++;
	}
	while (src[count2] != '\0' && count2 < n)
	{
		dst[count] = src[count2];
		count++;
		count2++;
	}
	dst[count] = '\0';
	return (dst);
}
