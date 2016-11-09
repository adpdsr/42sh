/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_prog.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fviolin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/28 16:06:21 by fviolin           #+#    #+#             */
/*   Updated: 2016/07/31 22:31:31 by gwells           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>
#include <builtins.h>
#include "lineedit.h"

void		free_env(t_env **env)
{
	t_env	*next;

	while (*env)
	{
		next = (*env)->next;
		free((*env)->name);
		free((*env)->content);
		free(*env);
		*env = next;
	}
}

static void	free_var(t_var **var)
{
	t_var	*next;

	while (*var)
	{
		next = (*var)->next;
		free((*var)->name);
		free((*var)->content);
		free(*var);
		*var = next;
	}
}

void		free_prog(t_var **var, t_env **env)
{
	free_singleton();
	free_var(var);
	free_env(env);
}
