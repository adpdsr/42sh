/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwells <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 15:14:09 by gwells            #+#    #+#             */
/*   Updated: 2015/03/22 10:08:34 by gwells           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*null(char *s)
{
	unsigned int	size;
	char			*str;

	size = ft_strlen(s) + 1;
	str = ft_memalloc_fail(size);
	ft_strcpy(str, s);
	return (str);
}

char				*ft_strjoin(char const *s1, char const *s2)
{
	unsigned int	size;
	char			*str;

	if (!s1 && s2)
		return (null((char*)s2));
	else if (!s2 && s1)
		return (null((char*)s1));
	else if (s1 && s2)
	{
		size = ft_strlen(s1) + ft_strlen(s2) + 1;
		str = ft_memalloc_fail(size);
		if (str == NULL)
			return (NULL);
		ft_strcpy(str, s1);
		ft_strcat(str, s2);
		return (str);
	}
	return (NULL);
}
