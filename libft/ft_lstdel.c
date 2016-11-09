/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwells <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/22 10:23:17 by gwells            #+#    #+#             */
/*   Updated: 2016/04/22 10:23:19 by gwells           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void		ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*next;

	if (alst && del)
	{
		while (*alst)
		{
			(*del)((*alst)->content, (*alst)->content_size);
			next = (*alst)->next;
			free(*alst);
			(*alst) = next;
		}
		*alst = NULL;
	}
}
