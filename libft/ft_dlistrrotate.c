/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlistrrotate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwells <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/22 10:18:33 by gwells            #+#    #+#             */
/*   Updated: 2016/04/22 10:21:36 by gwells           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_dlistrrotate(t_dlist *lst)
{
	t_dnode *temp;

	if (lst->head && lst->queue)
	{
		temp = ft_dlistrpop(lst);
		ft_dlstadd(lst, temp);
	}
}
