/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstdel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwells <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/26 00:03:29 by gwells            #+#    #+#             */
/*   Updated: 2014/12/26 00:06:16 by gwells           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_dlstdel(t_dnode **alst, void (*del)(void *, size_t))
{
	t_dnode *next;

	if (alst && del)
	{
		while (*alst)
		{
			next = (*alst)->next;
			(*del)((*alst)->content, (*alst)->content_size);
			free(*alst);
			*alst = next;
		}
	}
}
