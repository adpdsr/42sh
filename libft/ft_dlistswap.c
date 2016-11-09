/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlistswap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwells <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/22 10:22:07 by gwells            #+#    #+#             */
/*   Updated: 2016/04/22 10:22:09 by gwells           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_dlistswap(t_dlist *lst)
{
	t_dnode *first;
	t_dnode *second;

	if (lst->length >= 2)
	{
		first = ft_dlistpop(lst);
		second = ft_dlistpop(lst);
		ft_dlstadd(lst, first);
		ft_dlstadd(lst, second);
	}
}
