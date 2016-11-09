/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwells <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 13:00:25 by gwells            #+#    #+#             */
/*   Updated: 2014/11/14 03:58:04 by gwells           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*str;
	unsigned int	count;

	if (s)
	{
		count = 0;
		str = ft_strnew(len);
		if (str == NULL)
			return (NULL);
		while (count < start)
		{
			s++;
			count++;
		}
		ft_strncpy(str, s, len);
		str[len] = '\0';
		return (str);
	}
	return (NULL);
}
