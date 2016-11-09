/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fviolin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/09 11:58:30 by fviolin           #+#    #+#             */
/*   Updated: 2016/08/09 11:59:26 by fviolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"
#include "processes.h"

char	*get_node_content(t_env *env, char *str)
{
	while (env)
	{
		if (!ft_strcmp(env->name, str))
			return (ft_strdup(env->content));
		env = env->next;
	}
	return (NULL);
}

void	set_node_content(t_env *env, char *index, char *content)
{
	while (env)
	{
		if (!ft_strcmp(env->name, index))
		{
			free(env->content);
			env->content = ft_strdup(content);
			return ;
		}
		env = env->next;
	}
}

void	env_push_back(t_env **head, t_env *new)
{
	t_env *cur;

	if (!*head)
		*head = new;
	else
	{
		cur = *head;
		while (cur->next)
			cur = cur->next;
		cur->next = new;
	}
}

t_env	*env_create_node(char *environ)
{
	t_env *new;

	if (!(new = (t_env *)malloc(sizeof(t_env))))
		return (NULL);
	new->content = get_var_content(environ);
	new->name = get_var_name(environ);
	new->next = NULL;
	return (new);
}

void	list_remove(t_env **node, char *var_name)
{
	t_env *tmp;

	tmp = *node;
	if (*node)
	{
		if (!ft_strcmp((*node)->name, var_name))
		{
			tmp = *node;
			*node = (*(node))->next;
			ft_strdel(&(tmp->name));
			ft_strdel(&(tmp->content));
			free(tmp);
			list_remove(&(*node), var_name);
		}
		else
			list_remove(&(*node)->next, var_name);
	}
}
