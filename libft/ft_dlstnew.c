/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwells <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/16 14:39:11 by gwells            #+#    #+#             */
/*   Updated: 2015/03/22 10:05:16 by gwells           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_dlist		*ft_dlstnew(void)
{
	t_dlist *lstnew;

	lstnew = (t_dlist*)ft_memalloc_fail(sizeof(*lstnew));
	if (lstnew)
	{
		lstnew->length = 0;
		lstnew->head = NULL;
		lstnew->queue = NULL;
	}
	return (lstnew);
}
