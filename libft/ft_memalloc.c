/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwells <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 17:08:19 by gwells            #+#    #+#             */
/*   Updated: 2014/11/13 16:25:20 by gwells           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void		*ft_memalloc(size_t size)
{
	char	*str;
	size_t	count;

	count = 0;
	str = malloc(size);
	if (str == NULL || size == 0)
		return (NULL);
	while (count != size)
	{
		str[count] = '\0';
		count++;
	}
	return (str);
}
