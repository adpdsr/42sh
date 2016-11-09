/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwells <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/22 09:51:06 by gwells            #+#    #+#             */
/*   Updated: 2016/04/22 14:01:57 by gwells           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

static size_t g_size_elem;
static size_t g_nb_elem;

int				diff(void const *a, void const *b)
{
	return (ft_memcmp(a, b, g_size_elem));
}

static void		copy(void *tab, size_t j)
{
	void	*temp;
	void	*a;
	void	*b;

	temp = ft_memalloc_fail(g_size_elem);
	a = tab + j * g_size_elem;
	b = tab + (j - 1) * g_size_elem;
	temp = ft_memcpy(temp, a, g_size_elem);
	a = ft_memcpy(a, b, g_size_elem);
	b = ft_memcpy(b, temp, g_size_elem);
	free(temp);
}

void			ft_isort(void *tab, size_t nb_elem, size_t size_elem,\
				int (*diff)(void const *a, void const *b))
{
	size_t	i;
	size_t	j;

	i = 1;
	g_size_elem = size_elem;
	g_nb_elem = nb_elem;
	while (i != g_nb_elem)
	{
		j = i;
		while (j && ((*diff)(tab + j * g_size_elem, tab\
				+ (j - 1) * g_size_elem) > 0))
		{
			copy(tab, j);
			j--;
		}
		i++;
	}
}
