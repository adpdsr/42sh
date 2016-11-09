/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fviolin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/28 16:27:32 by fviolin           #+#    #+#             */
/*   Updated: 2016/07/28 16:28:10 by fviolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>
#include <builtins.h>

static char		**get_exec_path(void)
{
	char			**res;
	char			*content;
	t_signal_var	*s;

	res = NULL;
	content = NULL;
	s = singleton();
	content = get_node_content(s->env, "PATH=");
	if (content)
	{
		res = ft_strsplit(content, ':');
		free(content);
		return (res);
	}
	free(content);
	return (NULL);
}

t_all			*init_all(t_all *all, char **environ)
{
	t_signal_var	*s;

	s = singleton();
	if (!(all = (t_all *)malloc(sizeof(t_all))))
		ft_error("error: malloc failed", 1);
	all->env = NULL;
	s->env = NULL;
	all->env = fill_env(&all->env, &s->env, environ, -1);
	if (!(all->term = (t_term *)malloc(sizeof(t_term))))
		ft_error("error: malloc failed", 1);
	all->paths = get_exec_path();
	all->env_tab = list_in_tab(s->env);
	if (!(all->exec = (t_exec *)malloc(sizeof(t_exec))))
		ft_error("error: malloc failed", 1);
	all->exec->fd_write = 0;
	all->exec->fd_read = 0;
	all->var = NULL;
	return (all);
}
