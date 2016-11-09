/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_errors.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adu-pelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/23 20:04:25 by adu-pelo          #+#    #+#             */
/*   Updated: 2016/07/23 20:05:33 by adu-pelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <builtins.h>

int	error_env(int err)
{
	if (err == 0)
		ft_putendl_fd("42sh: env: invalid options", 2);
	else
		ft_putendl_fd("42sh: env: invalid arguments", 2);
	ft_putstr_fd("42sh: env: usage: env [-u] [name ...] | ", 2);
	ft_putendl_fd("env [-i] [name=value ...] [binary ...]", 2);
	return (1);
}

int	error_history(int err)
{
	if (err == 0)
		ft_putendl_fd("42sh: history: offset out of range", 2);
	else if (err == 1)
		ft_putendl_fd("42sh: history: offset must digit", 2);
	else if (err == 2)
	{
		ft_putendl_fd("42sh: history: invalid options", 2);
		ft_putstr_fd("42sh: history: usage: ", 2);
		ft_putendl_fd("history [-c] | history [-d] [offset]", 2);
	}
	else if (err == 3)
	{
		ft_putendl_fd("42sh: history: wrong arguments", 2);
		ft_putstr_fd("42sh: history: usage: ", 2);
		ft_putendl_fd("history [-c] | history [-d] [offset]", 2);
	}
	else if (err == 4)
		ft_putendl_fd("42sh: history: too many arguments", 2);
	return (1);
}

int	error_setenv(int err)
{
	if (err == 0)
		ft_putendl_fd("42sh: setenv: too many arguments", 2);
	else if (err == 1)
	{
		ft_putstr_fd("42sh: setenv: var name must ", 2);
		ft_putendl_fd("contain alphanumeric characters", 2);
	}
	ft_putendl_fd("42sh: setenv: usage: setenv [name] [name value]", 2);
	return (1);
}

int	error_unset(int err)
{
	if (err == 0)
		ft_putendl_fd("42sh: unset: invalid options", 2);
	else if (err == 1)
		ft_putendl_fd("42sh: unset: too few arguments", 2);
	ft_putendl_fd("42sh: unset: usage: unset [-f] [-v] [name ...]", 2);
	return (1);
}

int	error_export(int err)
{
	if (err == 1)
	{
		ft_putendl_fd("42sh: export: invalid options", 2);
		ft_putendl_fd("42sh: export: usage: export [-p] [name ...]", 2);
	}
	return (1);
}
