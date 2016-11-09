/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlistpop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwells <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/22 10:04:39 by gwells            #+#    #+#             */
/*   Updated: 2016/04/22 10:06:02 by gwells           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_dnode			*ft_dlistpop(t_dlist *lst)
{
	t_dnode		*ret;

	ret = lst->head;
	if (lst->head)
	{
		lst->head = lst->head->next;
		if (lst->head)
			lst->head->prev = NULL;
		ret->prev = NULL;
		ret->next = NULL;
		lst->length--;
		if (lst->length == 1)
			lst->queue = lst->head;
		if (lst->length == 0)
			lst->queue = NULL;
	}
	return (ret);
}
