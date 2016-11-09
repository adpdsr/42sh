/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmapi.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwells <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 00:10:37 by gwells            #+#    #+#             */
/*   Updated: 2014/12/10 23:51:33 by gwells           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	int		count;

	count = 0;
	if (f && s)
	{
		str = ft_strdup(s);
		if (str == NULL)
			return (NULL);
		while (str[count] != '\0')
		{
			str[count] = f((unsigned int)count, str[count]);
			count++;
		}
		return (str);
	}
	return (NULL);
}
