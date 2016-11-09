/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwells <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/09 03:48:42 by gwells            #+#    #+#             */
/*   Updated: 2014/11/13 16:41:47 by gwells           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len_dst;
	size_t	len_src;

	len_dst = ft_strlen(dst);
	len_src = ft_strlen(src);
	if (len_dst > size - 1 || !size)
		return (size + len_src);
	while (size - 1 > 0 && *dst)
	{
		dst++;
		size--;
	}
	while (size - 1 > 0 && *src)
	{
		*dst = *src;
		dst++;
		src++;
		size--;
	}
	*dst = 0;
	return (len_dst + len_src);
}
