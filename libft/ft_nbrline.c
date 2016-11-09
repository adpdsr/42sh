/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrline.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwells <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/06 15:38:07 by gwells            #+#    #+#             */
/*   Updated: 2015/05/06 15:42:33 by gwells           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

int			ft_nbrline(int fd)
{
	char	*buffer;
	int		nbrline;
	int		i;

	nbrline = 1;
	buffer = ft_strnew(BUFF_SIZE);
	while (read(fd, buffer, BUFF_SIZE) > 0)
	{
		i = 0;
		while (buffer[i])
		{
			if (buffer[i] == '\n')
				nbrline++;
			i++;
		}
	}
	return (nbrline);
}
