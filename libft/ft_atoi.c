/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwells <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 00:41:16 by gwells            #+#    #+#             */
/*   Updated: 2014/12/11 01:33:28 by gwells           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int nb;
	int neg;

	nb = 0;
	neg = 1;
	while (*str && ft_isspace(*str))
		str++;
	if (*str && (*str == '-' || *str == '+'))
	{
		if (*str == '-')
			neg = -1;
		str++;
	}
	while (ft_isdigit(*str))
	{
		nb *= 10;
		nb += *str - '0';
		str++;
	}
	return (nb * neg);
}
