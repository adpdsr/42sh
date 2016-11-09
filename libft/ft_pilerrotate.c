/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pilerrotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwells <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/22 09:28:13 by gwells            #+#    #+#             */
/*   Updated: 2016/04/22 09:28:16 by gwells           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_pilerrotate(t_pile **pile)
{
	t_pile	*temp;
	t_pile	*before_last;

	if (pile && *pile)
	{
		temp = *pile;
		while (temp->prev->prev != NULL)
			temp = temp->prev;
		before_last = temp;
		temp->prev->prev = *pile;
		*pile = temp->prev;
		before_last->prev = NULL;
	}
}
