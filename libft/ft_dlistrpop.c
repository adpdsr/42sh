/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlistrpop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwells <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/22 10:04:09 by gwells            #+#    #+#             */
/*   Updated: 2016/04/22 10:06:34 by gwells           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dnode			*ft_dlistrpop(t_dlist *lst)
{
	t_dnode		*ret;

	ret = lst->queue;
	if (lst->queue)
	{
		lst->queue = lst->queue->prev;
		if (lst->queue)
			lst->queue->next = NULL;
		ret->prev = NULL;
		ret->next = NULL;
		lst->length--;
		if (lst->length == 1)
			lst->head = lst->queue;
		else if (lst->length == 0)
			lst->head = NULL;
	}
	return (ret);
}
