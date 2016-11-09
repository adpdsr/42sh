/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrbase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwells <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/31 17:27:12 by gwells            #+#    #+#             */
/*   Updated: 2015/05/13 12:10:57 by gwells           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbrbase(uintmax_t nbr, char *base, size_t base_len)
{
	if (nbr >= (unsigned int)base_len)
	{
		ft_putnbrbase(nbr / base_len, base, base_len);
		ft_putnbrbase(nbr % base_len, base, base_len);
	}
	else
		ft_putchar(base[nbr]);
}
