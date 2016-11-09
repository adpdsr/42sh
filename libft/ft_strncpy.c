/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwells <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 04:10:39 by gwells            #+#    #+#             */
/*   Updated: 2014/12/25 15:59:02 by gwells           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strncpy(char *dst, const char *src, size_t n)
{
	size_t	count;

	count = 0;
	while (dst && src[count] != '\0' && count < n)
	{
		dst[count] = src[count];
		count++;
	}
	while (src && dst && count < n)
	{
		dst[count] = '\0';
		count++;
	}
	return (dst);
}
