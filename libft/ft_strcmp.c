/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwells <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/07/10 15:56:21 by gwells            #+#    #+#             */
/*   Updated: 2014/12/11 01:34:41 by gwells           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_strcmp(char const *s1, char const *s2)
{
	int				i;
	unsigned char	*temp1;
	unsigned char	*temp2;

	i = 0;
	temp1 = (unsigned char*)s1;
	temp2 = (unsigned char*)s2;
	while (temp1[i] == temp2[i] && temp1[i] != '\0')
		i++;
	return (temp1[i] - temp2[i]);
}
