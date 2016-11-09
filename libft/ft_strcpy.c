/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwells <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 19:27:01 by gwells            #+#    #+#             */
/*   Updated: 2014/11/20 23:33:32 by gwells           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *dst, const char *src)
{
	unsigned int count;

	count = 0;
	while (src[count] != '\0')
	{
		dst[count] = src[count];
		count++;
	}
	dst[count] = '\0';
	return (dst);
}
