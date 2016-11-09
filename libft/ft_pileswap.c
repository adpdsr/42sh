/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pileswap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwells <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/22 09:21:18 by gwells            #+#    #+#             */
/*   Updated: 2016/04/22 09:21:23 by gwells           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_pileswap(t_pile **pile)
{
	void	*temp;

	if (pile && *pile)
	{
		temp = (*pile)->content;
		(*pile)->content = (*pile)->prev->content;
		(*pile)->prev->content = temp;
	}
}
