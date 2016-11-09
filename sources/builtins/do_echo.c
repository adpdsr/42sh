/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adu-pelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/01 15:34:25 by adu-pelo          #+#    #+#             */
/*   Updated: 2016/09/07 11:47:41 by adu-pelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>
#include <builtins.h>

static int	read_e_args(char **cmd, int i)
{
	int		j;
	int		k;

	while (cmd[i])
	{
		j = 0;
		k = 0;
		while (cmd[i][j])
		{
			k = j;
			j = print_echo(cmd[i], j);
			if (j == k - 1)
				return (1);
		}
		if (cmd[i + 1])
			ft_putchar(' ');
		i++;
	}
	return (0);
}

static void	parse_echo(char **cmd, int i, int e, int n)
{
	if (e)
	{
		if ((read_e_args(cmd, i)) != 0)
			return ;
	}
	else
	{
		while (cmd[i])
		{
			ft_putstr(cmd[i]);
			if (cmd[i + 1])
				ft_putchar(' ');
			i++;
		}
	}
	if (!n)
		ft_putchar('\n');
}

static void	replace_retval_and_dollar(char **cmd)
{
	int				i;
	char			*tmp;
	t_signal_var	*s;

	i = 0;
	tmp = NULL;
	s = singleton();
	while (cmd[i])
	{
		if (!ft_strcmp(cmd[i], "$?"))
		{
			free(cmd[i]);
			cmd[i] = ft_itoa(s->ret);
			return ;
		}
		i++;
	}
}

static int	read_echo_options(char **cmd, int *opt, int i)
{
	int j;

	opt[0] = 0;
	opt[1] = 0;
	while (cmd[++i])
	{
		if (cmd[i][0] == '-')
		{
			j = 0;
			while (cmd[i][++j])
			{
				if (cmd[i][j] == 'e')
					opt[0] = 1;
				else if (cmd[i][j] == 'n')
					opt[1] = 1;
				else
					return (-1);
			}
		}
		else
			return (i);
	}
	return (i);
}

int			do_echo(t_input *input, t_env **env, t_var **var, char **cmd)
{
	int		i;
	int		opt[2];

	i = 0;
	(void)var;
	(void)env;
	(void)input;
	if ((i = read_echo_options(cmd, opt, 0)) == -1)
	{
		ft_putendl_fd("42sh: echo: unvalid option", 2);
		ft_putendl_fd("42sh: echo: usage: echo [-en] [string]", 2);
		return (1);
	}
	if (cmd[i])
	{
		replace_retval_and_dollar(cmd);
		parse_echo(cmd, i, opt[0], opt[1]);
	}
	else if (opt[1] == 0)
		ft_putchar('\n');
	return (0);
}
