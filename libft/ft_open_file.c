/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwells <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/22 09:47:19 by gwells            #+#    #+#             */
/*   Updated: 2016/04/23 17:56:02 by gwells           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int			ft_open_file(char *str, int flag)
{
	int		fd;

	if ((fd = open(str, flag)) == -1)
	{
		ft_putendl("Open file failed");
		exit(EXIT_FAILURE);
	}
	return (fd);
}
