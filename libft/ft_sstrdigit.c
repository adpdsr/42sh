/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sstrdigit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwells <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/24 10:52:03 by gwells            #+#    #+#             */
/*   Updated: 2016/07/24 10:52:12 by gwells           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isstrdigit(char *s)
{
	int i;

	i = -1;
	if (s)
	{
		while (s[++i])
		{
			if (s[i] < '0' || s[i] > '9')
				return (0);
		}
		return (1);
	}
	return (0);
}
