/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwells <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 23:32:36 by gwells            #+#    #+#             */
/*   Updated: 2014/12/10 23:50:49 by gwells           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmap(char const *s, char (*f)(char))
{
	char	*str;
	int		count;

	count = 0;
	if (s && f)
	{
		str = ft_strdup(s);
		if (str == NULL)
			return (NULL);
		while (str[count] != '\0')
		{
			str[count] = f(s[count]);
			count++;
		}
		return (str);
	}
	return (NULL);
}
