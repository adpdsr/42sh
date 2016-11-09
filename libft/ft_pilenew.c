/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pilenew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwells <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/22 09:30:31 by gwells            #+#    #+#             */
/*   Updated: 2016/04/22 09:32:48 by gwells           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_pile		*ft_pilenew(void const *content, size_t content_size)
{
	t_pile	*new;

	new = (t_pile*)ft_memalloc_fail(sizeof(*new));
	if (content == NULL)
	{
		new->content = NULL;
		new->content_size = 0;
	}
	else
	{
		new->content = (void *)ft_memalloc(content_size);
		if (new->content == NULL)
		{
			free(new);
			return (NULL);
		}
		ft_memcpy(new->content, content, content_size);
		new->content_size = content_size;
	}
	new->prev = NULL;
	return (new);
}
