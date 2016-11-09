/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwells <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 14:58:16 by gwells            #+#    #+#             */
/*   Updated: 2014/11/13 16:45:35 by gwells           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strrchr(const char *str, int c)
{
	char	*strchr;
	int		length;

	length = (int)ft_strlen(str);
	strchr = NULL;
	while (length >= 0)
	{
		if (*(str + length) == c)
		{
			strchr = (char *)str + length;
			return (strchr);
		}
		length--;
	}
	return (NULL);
}
