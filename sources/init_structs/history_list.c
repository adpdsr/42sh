/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adu-pelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/24 20:21:32 by adu-pelo          #+#    #+#             */
/*   Updated: 2016/09/02 13:20:20 by adu-pelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lineedit.h"

t_his		*his_create_node(char *cmd)
{
	t_his	*new;

	new = (t_his *)ft_memalloc_fail(sizeof(t_his));
	new->next = NULL;
	new->prev = NULL;
	new->select = 0;
	new->listed = 0;
	new->cmd = ft_strdup(cmd);
	new->end = 0;
	return (new);
}

t_his		*his_push_back(t_his **head, t_his *new)
{
	t_his	*cur;

	if (!*head)
		*head = new;
	else
	{
		cur = *head;
		while (cur->next)
			cur = cur->next;
		cur->next = new;
		new->prev = cur;
	}
	return (*head);
}
