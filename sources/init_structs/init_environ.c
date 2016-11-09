/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_environ.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fviolin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/28 16:28:23 by fviolin           #+#    #+#             */
/*   Updated: 2016/08/09 12:01:59 by fviolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"
#include "lineedit.h"
#include "builtins.h"

static void	create_hist_var(t_env **tenv, t_env **cp,
		int is_histfile, int is_histsize)
{
	char	*tmp;

	if (!is_histfile)
	{
		tmp = ft_strjoin("HISTFILE=", HPATH);
		env_push_back(tenv, env_create_node(tmp));
		free(tmp);
		tmp = ft_strjoin("HISTFILE=", HPATH);
		env_push_back(cp, env_create_node(tmp));
		free(tmp);
	}
	if (!is_histsize)
	{
		env_push_back(tenv, env_create_node("HISTSIZE=300"));
		env_push_back(cp, env_create_node("HISTSIZE=300"));
	}
}

static void	add_pwd(t_env **env, t_env **cp, char **environ)
{
	int		i;
	char	*tmp;
	char	cwd[PATH_MAX_SIZE];

	i = 0;
	getcwd(cwd, PATH_MAX_SIZE);
	while (environ[i])
	{
		if (ft_strstr(environ[i], "PWD="))
			return ;
		i++;
	}
	tmp = ft_strjoin("PWD=", cwd);
	env_push_back(env, env_create_node(tmp));
	env_push_back(cp, env_create_node(tmp));
	free(tmp);
}

t_env		*fill_env(t_env **tenv, t_env **cp, char **environ, int i)
{
	int				is_histsize;
	int				is_histfile;
	t_signal_var	*s;

	is_histsize = 0;
	is_histfile = 0;
	s = singleton();
	while (environ[++i])
	{
		if (ft_strstr(environ[i], "HISTSIZE="))
			is_histsize = 1;
		else if (ft_strstr(environ[i], "HISTFILE="))
			is_histfile = 1;
	}
	i = -1;
	while (environ[++i])
		env_push_back(tenv, env_create_node(environ[i]));
	i = -1;
	while (environ[++i])
		env_push_back(cp, env_create_node(environ[i]));
	create_hist_var(tenv, cp, is_histfile, is_histsize);
	add_pwd(tenv, cp, environ);
	s->env = *cp;
	return (*tenv);
}
