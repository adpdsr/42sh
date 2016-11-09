/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strpbrk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwells <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/11 20:02:43 by gwells            #+#    #+#             */
/*   Updated: 2016/07/24 10:50:13 by gwells           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strpbrk2(const char *s1, const char *s2)
{
	int			i;
	char		*ret;
	char		*tmp;

	i = 0;
	ret = (char*)s1 + ft_strlen(s1);
	while (s2[i])
	{
		tmp = ft_strchr(s1, (int)s2[i]);
		if (tmp != NULL)
		{
			if (tmp < ret)
				ret = tmp;
		}
		i++;
	}
	if (ret == (char*)s1 + ft_strlen(s1))
		return (NULL);
	return (ret);
}
