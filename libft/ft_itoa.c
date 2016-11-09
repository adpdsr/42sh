/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwells <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 18:24:26 by gwells            #+#    #+#             */
/*   Updated: 2014/11/13 16:18:36 by gwells           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_len(int n)
{
	int				len;
	int unsigned	nb;

	len = 0;
	if (n < 0)
	{
		len++;
		nb = -n;
	}
	else
		nb = n;
	while (nb >= 10)
	{
		nb = nb / 10;
		len++;
	}
	return (len + 1);
}

void				createstr(int len, unsigned int nb, int neg, char *str)
{
	while (len >= 0)
	{
		str[len] = '0' + (nb % 10);
		nb = nb / 10;
		if (neg && len == 1)
			break ;
		len--;
	}
}

char				*ft_itoa(int n)
{
	char			*str;
	int				len;
	int				neg;
	unsigned int	nb;

	neg = 0;
	len = ft_len(n);
	str = ft_strnew(len);
	if (str == NULL)
		return (NULL);
	len--;
	if (n < 0)
	{
		nb = -n;
		neg = 1;
	}
	else
		nb = n;
	createstr(len, nb, neg, str);
	if (neg)
		str[0] = '-';
	return (str);
}
