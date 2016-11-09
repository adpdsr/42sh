/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pilepush.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwells <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/22 09:35:04 by gwells            #+#    #+#             */
/*   Updated: 2016/04/22 09:35:33 by gwells           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_pilepush(t_pile **pile, t_pile *newnode)
{
	t_pile	*temp;

	if (pile && newnode)
	{
		temp = *pile;
		*pile = newnode;
		(*pile)->prev = temp;
	}
}
