/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptrfunc_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adu-pelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/25 09:09:13 by adu-pelo          #+#    #+#             */
/*   Updated: 2016/08/24 13:46:39 by gwells           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>
#include <builtins.h>

static int		option_handle(char **cmd, t_env *env)
{
	int			err;
	char		*resolved_cmd;

	resolved_cmd = NULL;
	if (!ft_strcmp(cmd[1], "-P") || !ft_strcmp(cmd[1], "-PL"))
	{
		resolved_cmd = resolve_dir(cmd[2], env, 1);
		err = change_directory(env, resolved_cmd, 1);
	}
	else if (!ft_strcmp(cmd[1], "-L") || !ft_strcmp(cmd[1], "-LP"))
	{
		resolved_cmd = resolve_dir(cmd[2], env, 0);
		err = change_directory(env, resolved_cmd, 0);
	}
	else
	{
		ft_putendl_fd("Not a valid option", 2);
		err = 1;
	}
	free(resolved_cmd);
	return (err);
}

static int		basic_handle(char **cmd, t_env *env)
{
	int			err;
	char		*resolved_cmd;

	resolved_cmd = resolve_dir(cmd[1], env, 0);
	err = change_directory(env, resolved_cmd, 0);
	free(resolved_cmd);
	return (err);
}

static int		only_cd(char **cmd, t_env *env)
{
	int			err;
	char		*resolved_cmd;

	(void)cmd;
	resolved_cmd = resolve_dir("", env, 0);
	err = change_directory(env, resolved_cmd, 0);
	free(resolved_cmd);
	return (err);
}

static void		init_cdptr(t_func_cd *ptrfunc)
{
	ptrfunc[0] = &only_cd;
	ptrfunc[1] = &basic_handle;
	ptrfunc[2] = &option_handle;
}

int				cmd_handle(char **cmd, t_env *env)
{
	int			len;
	t_func_cd	ptrcd[3];

	len = ft_tablen(cmd);
	if (len > 3)
	{
		ft_putendl_fd("cd : Too few arguments", 2);
		return (1);
	}
	init_cdptr(ptrcd);
	return (ptrcd[len - 1](cmd, env));
}
