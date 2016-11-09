/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpushback.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwells <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/22 09:37:45 by gwells            #+#    #+#             */
/*   Updated: 2016/04/22 09:38:03 by gwells           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstpushback(t_list **begin_list, t_list *new)
{
	t_list	*string;

	if (*begin_list)
	{
		string = *begin_list;
		while (string->next)
			string = string->next;
		string->next = new;
	}
	else
		*begin_list = new;
}
