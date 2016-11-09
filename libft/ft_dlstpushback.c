/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstpushback.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwells <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/17 12:03:31 by gwells            #+#    #+#             */
/*   Updated: 2015/01/07 21:30:25 by gwells           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dlstpushback(t_dlist *lst, t_dnode *newnode)
{
	if (lst != NULL && newnode != NULL)
	{
		if (lst->queue == NULL)
		{
			lst->queue = newnode;
			lst->head = newnode;
		}
		else
		{
			lst->queue->next = newnode;
			newnode->prev = lst->queue;
			lst->queue = newnode;
		}
		lst->length++;
	}
}
