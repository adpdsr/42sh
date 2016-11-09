/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_unsetenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwells <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/24 14:05:49 by gwells            #+#    #+#             */
/*   Updated: 2016/08/24 14:07:33 by gwells           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>
#include <builtins.h>

static int			error1_unsetenv(void)
{
	ft_error("42sh: unsetenv: too few arguments", 0);
	ft_error("42sh: unsetenv: usage: unsetenv [name ...]", 0);
	return (1);
}

static int			error2_unsetenv(void)
{
	ft_putstr_fd("42sh: unsetenv: var name must ", 2);
	ft_error("contain alphanumeric characters", 0);
	ft_error("42sh: unsetenv: usage: unsetenv [name ...]", 0);
	return (1);
}

static char			*modif_cmd(char *cmd)
{
	char			*cpy;

	cpy = NULL;
	cpy = ft_strjoin(cmd, "=");
	ft_strdel(&cmd);
	cmd = ft_strdup(cpy);
	ft_strdel(&cpy);
	return (cmd);
}

int					do_unsetenv(t_input *input, t_env **env,\
t_var **var, char **cmd)
{
	int				i;
	int				j;
	int				len;
	t_signal_var	*s;

	i = 0;
	j = 0;
	(void)var;
	(void)input;
	len = ft_tablen(cmd);
	s = singleton();
	if (len == 1)
		return (error1_unsetenv());
	while (cmd[++j])
		if (!ft_isstralnum(cmd[j]))
			return (error2_unsetenv());
	while (cmd[++i])
	{
		if (ft_strcmp(cmd[i], "="))
			cmd[i] = modif_cmd(cmd[i]);
		list_remove(env, cmd[i]);
	}
	return (0);
}
