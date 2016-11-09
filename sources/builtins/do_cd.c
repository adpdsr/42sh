/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fviolin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/09 11:55:16 by fviolin           #+#    #+#             */
/*   Updated: 2016/08/09 20:30:38 by fviolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"
#include "builtins.h"

static char		*relative_or_abs_path(t_env *env, char *cmd, int opt)
{
	char	*curpath;
	char	*tmp;

	curpath = NULL;
	if (if_absolute(cmd))
		return (ft_strdup(cmd));
	if (ft_strncmp(cmd, ".", 1))
		curpath = cd_path_handle(env, cmd, 0);
	if (curpath && !if_absolute(curpath))
	{
		tmp = curpath;
		curpath = pwd_handle(env, tmp, opt);
		free(tmp);
	}
	else if (!curpath)
		curpath = pwd_handle(env, cmd, opt);
	return (curpath);
}

static char		*canonical_path(char *path)
{
	char	*tmp;
	char	*tmp2;
	char	*ret;

	tmp = posix_step_a_dot(path);
	tmp2 = posix_step_a_slash(tmp);
	free(tmp);
	tmp = apply_posix_dotdot(tmp2);
	tmp2 = del_last_point(tmp);
	free(tmp);
	ret = del_last_slash(tmp2);
	free(tmp2);
	return (ret);
}

char			*resolve_dir(char *cmd, t_env *env, int opt)
{
	char		*resolved_dir;
	char		*tmp;

	if (!(resolved_dir = resolve_home(cmd, env)))
		resolved_dir = relative_or_abs_path(env, cmd, opt);
	tmp = resolved_dir;
	if (tmp)
	{
		resolved_dir = canonical_path(tmp);
		free(tmp);
	}
	return (resolved_dir);
}

int				do_cd(t_input *input, t_env **env, t_var **var, char **cmd)
{
	char *path;

	(void)input;
	(void)var;
	(void)path;
	return (cmd_handle(cmd, *env));
}
