/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pilerotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwells <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/22 09:27:47 by gwells            #+#    #+#             */
/*   Updated: 2016/04/22 09:27:48 by gwells           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_pilerotate(t_pile **pile)
{
	t_pile	*save_first;
	t_pile	*temp;

	if (pile && *pile)
	{
		temp = *pile;
		save_first = *pile;
		*pile = (*pile)->prev;
		while (temp->prev != NULL)
			temp = temp->prev;
		save_first->prev = NULL;
		temp->prev = save_first;
	}
}
