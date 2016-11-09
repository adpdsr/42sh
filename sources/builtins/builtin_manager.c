/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_manager.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fviolin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/28 16:22:29 by fviolin           #+#    #+#             */
/*   Updated: 2016/09/05 11:41:50 by fviolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>
#include <builtins.h>

static void	init_ptr_builtins(t_func *ptrfunc)
{
	ptrfunc[CD] = &do_cd;
	ptrfunc[ENV] = &do_env;
	ptrfunc[SETEV] = &do_setenv;
	ptrfunc[USETEV] = &do_unsetenv;
	ptrfunc[BECHO] = &do_echo;
	ptrfunc[HISTORY] = &do_history;
	ptrfunc[EXPORT] = &do_export;
	ptrfunc[UNSET] = &do_unset;
	ptrfunc[EXIT] = &do_exit;
}

static char	**builtins_names(void)
{
	char	**names;

	names = ft_memalloc_fail(sizeof(char *) * (BUILTINS + 1));
	names[CD] = ft_strdup("cd");
	names[ENV] = ft_strdup("env");
	names[SETEV] = ft_strdup("setenv");
	names[USETEV] = ft_strdup("unsetenv");
	names[BECHO] = ft_strdup("echo");
	names[HISTORY] = ft_strdup("history");
	names[EXPORT] = ft_strdup("export");
	names[UNSET] = ft_strdup("unset");
	names[EXIT] = ft_strdup("exit");
	names[BUILTINS] = NULL;
	return (names);
}

char		*tab_to_str(char **cmd)
{
	int		i;
	char	*res;
	char	*tmp;

	i = -1;
	tmp = ft_strdup("");
	while (cmd[++i])
	{
		res = ft_strjoin(tmp, cmd[i]);
		ft_strdel(&tmp);
		if (cmd[i + 1])
		{
			tmp = ft_strjoin(res, " ");
			ft_strdel(&res);
		}
		else
			tmp = ft_strdup(res);
	}
	ft_strdel(&tmp);
	return (res);
}

static void	free_names(char **names)
{
	int i;

	i = -1;
	while (names[++i])
		ft_strdel(&names[i]);
	free(names);
	names = NULL;
}

int			while_builtins(t_input *input, t_env **env, t_var **var, char **cmd)
{
	int		i;
	char	**names;
	t_func	builtins[BUILTINS];

	i = 0;
	names = builtins_names();
	init_ptr_builtins(builtins);
	while (i != BUILTINS)
	{
		if (!ft_strcmp(names[i], cmd[0]))
		{
			free_names(names);
			return (builtins[i](input, env, var, cmd));
		}
		i++;
	}
	free_names(names);
	return (check_shell_var(var, cmd));
}
