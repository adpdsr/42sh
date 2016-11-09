/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adu-pelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/25 09:14:26 by adu-pelo          #+#    #+#             */
/*   Updated: 2016/09/08 12:27:13 by fviolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"
#include "lineedit.h"

static void	color(char *str, char *col)
{
	ft_putstr("\e");
	ft_putstr(col);
	ft_putstr(str);
	ft_putstr("\033[0m");
}

static void	put_home(char *home, char *cwd)
{
	color("~", CYAN);
	color((ft_strstr(cwd, home) + ft_strlen(home)), CYAN);
}

static int	prompt_handle(char *user, int i)
{
	if (user)
	{
		i = ft_strlen(user) + 1;
		color(user, YELLOW);
		ft_putchar(' ');
	}
	else
	{
		color("incognito ", RED);
		i = 10;
	}
	return (i);
}

static int	put_prompt(char *user, char *home, char *cwd)
{
	int i;

	i = 5;
	i = prompt_handle(user, i);
	if (cwd && home && ft_strstr(cwd, home))
	{
		i += ft_strlen(ft_strstr(cwd, home) + ft_strlen(home)) + 1;
		put_home(home, cwd);
		ft_strdel(&cwd);
	}
	else if (cwd && cwd[0])
	{
		i += ft_strlen(cwd);
		color(cwd, CYAN);
		ft_strdel(&cwd);
	}
	else
	{
		i += 7;
		color("nowhere", RED);
	}
	ft_putstr(" $> ");
	ft_strdel(&user);
	ft_strdel(&home);
	return (i);
}

int			prompt(t_env *env)
{
	char			*user;
	char			*home;
	char			*cwd;
	int				i;
	t_signal_var	*s;

	s = singleton();
	user = get_node_content(env, "USER=");
	home = get_node_content(env, "HOME=");
	cwd = get_node_content(env, "PWD=");
	i = put_prompt(user, home, cwd);
	buffer_to_cursor(i + 4, s->input->cursor);
	return (i);
}
