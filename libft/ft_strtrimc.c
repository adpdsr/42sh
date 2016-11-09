/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrimc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwells <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/24 10:45:13 by gwells            #+#    #+#             */
/*   Updated: 2016/07/24 10:45:15 by gwells           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrimc(char const *s, char const c)
{
	char	*str;
	size_t	len;
	size_t	count;

	if (s)
	{
		count = 0;
		len = 0;
		while (*s && *s == c)
			s++;
		len = ft_strlen(s);
		while (*s && (*(s + len - 1)) == c)
		{
			count++;
			len--;
		}
		str = ft_strsub(s, 0, len);
		return (str);
	}
	return ((char*)s);
}
