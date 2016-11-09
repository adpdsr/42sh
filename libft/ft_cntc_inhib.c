/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cntc_inhib.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwells <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/05 14:28:45 by gwells            #+#    #+#             */
/*   Updated: 2016/09/05 14:44:12 by gwells           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_cntc_inhib(t_inhib *line, char *str, char c)
{
	int i;
	int cnt;

	if (str && c)
	{
		i = 0;
		cnt = 0;
		while (str[i])
		{
			if (str[i] == c && line[i].active)
				cnt++;
			i++;
		}
		return (cnt);
	}
	return (0);
}
