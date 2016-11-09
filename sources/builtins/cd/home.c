/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   home.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fviolin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/09 11:47:14 by fviolin           #+#    #+#             */
/*   Updated: 2016/08/09 11:48:49 by fviolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"
#include "builtins.h"

static char	*old_to_new(t_env *env)
{
	char *ret;

	if ((ret = get_node_content(env, "OLDPWD=")))
		return (ret);
	return (NULL);
}

static char	*minus_home(t_env *env)
{
	char *resolved_dir;

	resolved_dir = get_node_content(env, "HOME=");
	return (resolved_dir);
}

char		*resolve_home(char *cmd, t_env *env)
{
	char *resolved_dir;
	char *tmp;

	resolved_dir = NULL;
	if (!ft_strcmp("-", cmd))
		return (old_to_new(env));
	if (!ft_strcmp("~", cmd) || !ft_strcmp("", cmd))
		return (minus_home(env));
	else if (cmd[0] == '~' && cmd[1] == '/'\
	&& (tmp = get_node_content(env, "HOME=")))
	{
		resolved_dir = path_join(tmp, &cmd[2]);
		free(tmp);
		return (resolved_dir);
	}
	return (NULL);
}
