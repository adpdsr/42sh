/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwells <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 15:47:30 by gwells            #+#    #+#             */
/*   Updated: 2014/11/13 16:47:02 by gwells           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrim(char const *s)
{
	char	*str;
	size_t	len;
	size_t	count;

	if (s)
	{
		count = 0;
		len = 0;
		while (*s && ft_isspace(*s))
			s++;
		len = ft_strlen(s);
		while (*s && ft_isspace(*(s + len - 1)))
		{
			count++;
			len--;
		}
		str = ft_strsub(s, 0, len);
		return (str);
	}
	return ((char*)s);
}
