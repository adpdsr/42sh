/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pilepop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwells <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/22 09:45:05 by gwells            #+#    #+#             */
/*   Updated: 2016/04/22 09:45:58 by gwells           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_pile			*ft_pilepop(t_pile **pile)
{
	t_pile		*temp;

	temp = NULL;
	if (pile && *pile)
	{
		temp = *pile;
		*pile = (*pile)->prev;
	}
	return (temp);
}
