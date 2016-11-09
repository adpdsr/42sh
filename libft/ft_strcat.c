/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwells <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 07:04:06 by gwells            #+#    #+#             */
/*   Updated: 2014/12/28 19:16:57 by gwells           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	int count;
	int count2;

	count = 0;
	count2 = 0;
	while (s1[count] != '\0')
	{
		count++;
	}
	while (s2[count2] != '\0')
	{
		s1[count] = s2[count2];
		count++;
		count2++;
	}
	s1[count] = '\0';
	return (s1);
}
