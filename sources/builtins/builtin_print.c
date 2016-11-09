/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fviolin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/28 16:14:25 by fviolin           #+#    #+#             */
/*   Updated: 2016/07/28 16:14:27 by fviolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>
#include <builtins.h>

static void	print_exported_vars(t_var *tmp)
{
	if (tmp->exported == 1)
	{
		ft_putstr("export ");
		ft_putstr(tmp->name);
		ft_putendl(tmp->content);
	}
}

static void	print_all_vars(t_var *tmp)
{
	if (tmp->is_func == 1)
	{
		ft_putstr(tmp->name);
		ft_putstr(" ()\n{\n\t");
		ft_putendl(tmp->content);
		ft_putendl("}");
	}
	else
	{
		ft_putstr(tmp->name);
		ft_putendl(tmp->content);
	}
}

void		print_vars(t_var *head, int only_exported)
{
	int		i;
	t_var	*tmp;

	i = 1;
	tmp = head;
	while (tmp)
	{
		if (only_exported == 0)
			print_all_vars(tmp);
		else
			print_exported_vars(tmp);
		tmp = tmp->next;
		i++;
	}
}

void		print_history(t_his **head, int len)
{
	int		i;
	int		sp;
	t_his	*tmp;

	i = 1;
	tmp = *head;
	while (tmp)
	{
		sp = -1;
		while (sp++ < (len - (int)ft_nbrlen(i)))
			ft_putchar(' ');
		ft_putnbr(i);
		ft_putstr("  ");
		ft_putendl(tmp->cmd);
		tmp = tmp->next;
		i++;
	}
}

int			print_echo(char *cmd, int j)
{
	if (cmd[j + 1] == '\\' && cmd[j + 2] == 'b')
		return (j + 3);
	else if (cmd[j] == '\\')
	{
		if (cmd[j + 1] == 'c')
			return (j - 1);
		else if (cmd[j + 1] == 'n')
			ft_putchar('\n');
		else if (cmd[j + 1] == 'r')
			ft_putchar('\r');
		else if (cmd[j + 1] == 't')
			ft_putchar('\t');
		else if (cmd[j + 1] == 'v')
			ft_putchar('\v');
		else if (cmd[j + 1] == '\\')
			ft_putchar('\\');
		else
			ft_putchar(cmd[j]);
		return (j + 2);
	}
	else
		ft_putchar(cmd[j]);
	return (j + 1);
}
