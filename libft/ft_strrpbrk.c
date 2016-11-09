/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrpbrk.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwells <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/12 11:57:19 by gwells            #+#    #+#             */
/*   Updated: 2016/07/24 10:48:58 by gwells           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strrpbrk(const char *s1, const char *s2)
{
	int			i;
	char		*ret;
	char		*tmp;

	i = 0;
	ret = (char*)s1 + ft_strlen(s1) - 1;
	while (s2[i])
	{
		tmp = ft_strrchr(s1, (int)s2[i]);
		if (tmp != NULL)
		{
			if (tmp < ret)
				ret = tmp;
		}
		i++;
	}
	if (tmp == NULL)
		return ((char*)s1);
	return (ret + 1);
}
