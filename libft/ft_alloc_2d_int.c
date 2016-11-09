/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alloc_2d_int.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwells <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/22 08:28:01 by gwells            #+#    #+#             */
/*   Updated: 2016/04/22 08:31:47 by gwells           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			**ft_alloc_2d_int_tab(int x, int y)
{
	int		**map;

	map = (int**)ft_memalloc_fail(sizeof(int*) * y);
	while (y-- != 0)
		map[y] = (int*)ft_memalloc_fail(sizeof(int) * x);
	return (map);
}
