/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_qsort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwells <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/22 08:35:31 by gwells            #+#    #+#             */
/*   Updated: 2016/04/22 14:01:26 by gwells           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/*
**A verifier j'ai changer const
*/

static size_t g_nb_elem;
static size_t g_size_elem;
int(*g_diff)(void *const a, void *const b);

static void		swap(void *const start_tab, const int a, const int b)
{
	void	*a_add;
	void	*b_add;
	void	*temp;

	a_add = (start_tab) + a * g_size_elem;
	b_add = (start_tab) + b * g_size_elem;
	temp = ft_memalloc_fail(g_size_elem);
	temp = ft_memcpy(temp, a_add, g_size_elem);
	a_add = ft_memcpy(a_add, b_add, g_size_elem);
	b_add = ft_memcpy(b_add, temp, g_size_elem);
	free(temp);
}

static size_t	partition(void *const start_tab, int premier, int dernier)
{
	int i;
	int j;

	j = premier;
	i = j;
	while (i != dernier)
	{
		if ((*g_diff)(start_tab + dernier * g_size_elem, start_tab + i\
			* g_size_elem) < 0)
		{
			swap(start_tab, j, i);
			j++;
		}
		i++;
	}
	swap(start_tab, dernier, j);
	return (j);
}

static void		quicksortrec(void *tab, int premier, int dernier)
{
	int pivot;

	if (premier < dernier)
	{
		pivot = partition(tab, premier, dernier);
		quicksortrec(tab, premier, pivot - 1);
		quicksortrec(tab, pivot + 1, dernier);
	}
}

void			ft_qsort(void *tab, size_t nb_elem, size_t size_elem,\
				int (*diff)(void *const a, void *const b))
{
	g_nb_elem = nb_elem;
	g_size_elem = size_elem;
	g_diff = diff;
	quicksortrec(tab, 0, nb_elem - 1);
}
