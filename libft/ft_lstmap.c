/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwells <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/11 23:09:56 by gwells            #+#    #+#             */
/*   Updated: 2014/12/28 21:19:24 by gwells           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*temp;
	t_list	*new;

	new = NULL;
	temp = NULL;
	while (lst && f)
	{
		temp = ft_lstnew(lst->content, lst->content_size);
		if (temp == NULL)
			return (NULL);
		ft_lstpushback(&new, f(temp));
		lst = lst->next;
	}
	return (new);
}
