/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isstralnum.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwells <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/24 10:53:39 by gwells            #+#    #+#             */
/*   Updated: 2016/07/24 10:53:48 by gwells           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isstralnum(char *s)
{
	int i;

	i = -1;
	while (s[++i])
	{
		if (s[i] != '_' && ft_isalnum(s[i]) == 0)
			return (0);
	}
	return (1);
}
