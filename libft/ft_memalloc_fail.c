/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc_fail.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwells <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/22 09:36:35 by gwells            #+#    #+#             */
/*   Updated: 2016/04/22 09:36:57 by gwells           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void		*ft_memalloc_fail(size_t size)
{
	char	*str;

	if (!(str = ft_memalloc(size)))
		ft_quit("Malloc failed", 2, EXIT_FAILURE);
	return (str);
}
