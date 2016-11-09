/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstinsert.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwells <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/16 20:08:37 by gwells            #+#    #+#             */
/*   Updated: 2014/12/25 14:51:16 by gwells           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstinsert(t_list *head, t_list *newnode, size_t pos)
{
	size_t	i;
	t_list	*temp;

	i = 0;
	temp = head;
	if (pos > ft_list_size(head))
		return (NULL);
	if (pos == 0)
		ft_lstadd(&head, newnode);
	if (pos == ft_list_size(head))
		ft_lstpushback(&head, newnode);
	while (temp && i <= pos)
	{
		if (i + 1 == pos)
			newnode->next = temp->next;
		if (pos - 1 == i)
			temp->next = newnode;
		else if (pos + 1 == i)
			ft_lstadd(&temp, newnode);
		temp = temp->next;
		i++;
	}
	return (head);
}
