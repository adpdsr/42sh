/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwells <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/31 22:33:31 by gwells            #+#    #+#             */
/*   Updated: 2016/09/04 14:12:59 by fviolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>
#include <builtins.h>

static int		delete_var(t_var **head, t_var *cur, t_var *prev)
{
	if (!cur->is_func)
	{
		if (cur == *head)
		{
			if (cur->next)
				*head = cur->next;
			else
			{
				free((*head)->name);
				free((*head)->content);
				free(*head);
				*head = NULL;
			}
		}
		else if (!cur->next)
			prev->next = NULL;
		else
			prev->next = cur->next;
		return (1);
	}
	return (0);
}

static int		delete_func(t_var **head, t_var *cur, t_var *prev)
{
	if (cur->is_func)
	{
		if (cur == *head)
		{
			if (cur->next)
				*head = cur->next;
			else
			{
				free((*head)->name);
				free((*head)->content);
				free(*head);
				*head = NULL;
			}
		}
		else if (!cur->next)
			prev->next = NULL;
		else
			prev->next = cur->next;
		return (1);
	}
	return (0);
}

static void		delete_var_node_norme(t_var **head, t_var *cur,\
	t_var *prev, int *opt)
{
	if (opt[0] && !opt[1])
		delete_var(head, cur, prev);
	else if (!opt[0] && opt[1])
		delete_func(head, cur, prev);
	else
	{
		if (!delete_var(head, cur, prev))
			delete_func(head, cur, prev);
	}
}

void			delete_var_node(t_var **head, t_var *cur,\
	char *to_del, int *opt)
{
	t_var		*prev;
	char		*tmp;

	if (*head)
	{
		while (cur)
		{
			tmp = ft_strjoin(to_del, "=");
			if ((cur->is_func && !ft_strcmp(cur->name, to_del)) ||
			(!cur->is_func && !ft_strcmp(cur->name, tmp)))
			{
				delete_var_node_norme(head, cur, prev, opt);
				free(tmp);
				return ;
			}
			free(tmp);
			prev = cur;
			cur = cur->next;
		}
	}
}
