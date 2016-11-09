/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstnewnode.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwells <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/16 16:52:00 by gwells            #+#    #+#             */
/*   Updated: 2015/03/22 10:06:17 by gwells           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_dnode		*ft_dlstnewnode(void const *content, size_t content_size)
{
	t_dnode *lstnode;

	lstnode = (t_dnode*)ft_memalloc_fail(sizeof(*lstnode));
	if (!lstnode)
		return (NULL);
	if (content == NULL)
	{
		lstnode->content = NULL;
		lstnode->content_size = 0;
	}
	else
	{
		lstnode->content = (void *)ft_memalloc_fail(content_size);
		if (!lstnode->content)
			return (NULL);
		ft_memcpy(lstnode->content, content, content_size);
		lstnode->content_size = content_size;
	}
	lstnode->next = NULL;
	lstnode->prev = NULL;
	return (lstnode);
}
