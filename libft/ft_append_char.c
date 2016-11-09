/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_append_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwells <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/22 09:56:54 by gwells            #+#    #+#             */
/*   Updated: 2016/04/22 09:57:34 by gwells           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_append_char(char *str, char c)
{
	char	*ret;
	int		count;

	count = 0;
	ret = ft_memalloc_fail(ft_strlen(str) + 2);
	while (str[count])
	{
		ret[count] = str[count];
		count++;
	}
	ret[count] = c;
	ret[count + 1] = '\0';
	return (ret);
}
