/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstinsert.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwells <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/16 17:01:09 by gwells            #+#    #+#             */
/*   Updated: 2015/01/25 07:44:13 by gwells           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void			norme(t_dlist *lst, t_dnode *temp, t_dnode *newnode)
{
	temp->prev->next = newnode;
	newnode->prev = temp->prev;
	temp->prev = newnode;
	newnode->next = temp;
	lst->length++;
}

static t_dlist		*lststart(t_dlist *lst, t_dnode *newnode, size_t pos)
{
	if (pos <= 0)
		ft_dlstadd(lst, newnode);
	else
		ft_dlstpushback(lst, newnode);
	return (lst);
}

t_dlist				*ft_dlstinsert(t_dlist *lst, t_dnode *newnode, size_t pos)
{
	size_t			i;
	t_dnode			*temp;

	temp = lst->head;
	i = 0;
	while (temp && i <= pos)
	{
		if (pos == i)
		{
			if (!pos)
				ft_dlstadd(lst, newnode);
			else if (pos >= lst->length)
				ft_dlstpushback(lst, newnode);
			else
				norme(lst, temp, newnode);
		}
		else
			temp = temp->next;
		i++;
	}
	if (!temp)
		lststart(lst, newnode, pos);
	return (lst);
}
