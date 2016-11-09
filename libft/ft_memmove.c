/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwells <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 16:46:45 by gwells            #+#    #+#             */
/*   Updated: 2014/11/13 16:28:31 by gwells           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void		*ft_memmove(void *dst, const void *src, size_t len)
{
	void	*temp;

	if (dst && src)
	{
		if ((temp = malloc(len)) == NULL)
			return (NULL);
		ft_memcpy(temp, src, len);
		ft_memcpy(dst, temp, len);
		free(temp);
	}
	return (dst);
}
