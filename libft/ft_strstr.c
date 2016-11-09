/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwells <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 16:30:17 by gwells            #+#    #+#             */
/*   Updated: 2015/02/12 09:10:17 by gwells           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strstr(const char *s1, const char *s2)
{
	char		*ret;
	char		*temp1;
	char		*temp2;

	if (!*s2)
		return ((char*)s1);
	temp2 = (char*)s2;
	while (*s1)
	{
		ret = (char*)s1;
		temp1 = (char*)s1;
		while (*temp1 == *s2)
		{
			temp1++;
			s2++;
			if (*s2 == '\0')
				return ((char*)ret);
		}
		s1++;
		s2 = temp2;
	}
	return (NULL);
}
