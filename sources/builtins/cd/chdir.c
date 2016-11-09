/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chdir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fviolin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/09 18:00:23 by fviolin           #+#    #+#             */
/*   Updated: 2016/08/24 13:50:56 by gwells           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"
#include "builtins.h"

static void			change_for_cwd(t_env *env, char *path)
{
	char			cwd[PATH_MAX_SIZE];
	char			*old_path;
	t_signal_var	*s;

	s = singleton();
	(void)path;
	ft_bzero(cwd, PATH_MAX_SIZE);
	getcwd(cwd, PATH_MAX_SIZE);
	old_path = get_node_content(env, "PWD=");
	set_node_content(env, "OLDPWD=", old_path);
	free(old_path);
	set_node_content(env, "PWD=", cwd);
	set_node_content(s->env, "PWD=", cwd);
}

static void			change_for_relative(t_env *env, char *path)
{
	char			*old_path;
	t_signal_var	*s;

	s = singleton();
	old_path = get_node_content(env, "PWD=");
	set_node_content(env, "OLDPWD=", old_path);
	free(old_path);
	set_node_content(env, "PWD=", path);
	set_node_content(s->env, "PWD=", path);
}

int					change_directory(t_env *env, char *path, int opt)
{
	char			cwd[PATH_MAX_SIZE];

	ft_bzero(cwd, PATH_MAX_SIZE);
	getcwd(cwd, PATH_MAX_SIZE);
	if (!error(path))
	{
		if (ft_strcmp(cwd, path) || !ft_strcmp("/", path))
		{
			chdir(path);
			if (opt)
				change_for_cwd(env, path);
			else
				change_for_relative(env, path);
		}
		return (0);
	}
	return (1);
}
