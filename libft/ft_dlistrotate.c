/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlistrotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwells <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/22 10:02:07 by gwells            #+#    #+#             */
/*   Updated: 2016/04/22 10:02:18 by gwells           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_dlistrotate(t_dlist *lst)
{
	t_dnode *temp;

	if (lst->head && lst->queue)
	{
		temp = ft_dlistpop(lst);
		ft_dlstpushback(lst, temp);
	}
}
