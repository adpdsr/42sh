/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_history.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adu-pelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/27 14:46:23 by adu-pelo          #+#    #+#             */
/*   Updated: 2016/07/24 17:18:22 by adu-pelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>
#include <builtins.h>

static int	delete_history_offset(t_his **head, char *index, int len, int i)
{
	int		id;
	t_his	*tmp;

	tmp = *head;
	id = ft_atoi(index);
	if (id > len)
		return (error_history(0));
	else if (ft_isstrdigit(index) < 1)
		return (error_history(1));
	while (tmp && ++i < id)
		tmp = tmp->next;
	if (i == id)
	{
		if (*head == NULL || tmp == NULL)
			return (0);
		if (*head == tmp)
			*head = tmp->next;
		if (tmp->next != NULL)
			tmp->next->prev = tmp->prev;
		if (tmp->prev != NULL)
			tmp->prev->next = tmp->next;
		free(tmp);
	}
	return (0);
}

static int	read_history_options(char **cmd, int *opt, int i)
{
	int		j;

	opt[0] = 0;
	opt[1] = 0;
	while (cmd[++i])
	{
		if (cmd[i][0] == '-')
		{
			j = 0;
			while (cmd[i][++j])
			{
				if (cmd[i][j] == 'c')
					opt[0] = 1;
				else if (cmd[i][j] == 'd')
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

static void	print_history_end(t_his *his, int len, int offset)
{
	int		i;
	int		sp;
	int		hlen;

	i = 0;
	hlen = history_len(&his);
	while (his && i < (hlen - offset))
	{
		his = his->next;
		i++;
	}
	while (his)
	{
		sp = -1;
		while (sp++ < (len - (int)ft_nbrlen(i)))
			ft_putchar(' ');
		ft_putnbr(i + 1);
		ft_putstr("  ");
		ft_putendl(his->cmd);
		his = his->next;
		i++;
	}
}

static int	parse_history(t_signal_var *s, char **cmd, int *opt, int len_h)
{
	int		i;

	i = 1;
	if ((i = read_history_options(cmd, opt, 0)) == -1 ||
		(opt[0] == 1 && opt[1] == 1))
		return (error_history(2));
	else if (!opt[0] && !opt[1] && ft_isstrdigit(cmd[i]))
	{
		if (cmd[i + 1])
			return (error_history(4));
		print_history_end(s->input->history, ft_nbrlen(len_h), ft_atoi(cmd[i]));
	}
	else if (opt[0] == 1)
		return (delete_history(&(s->input->history)));
	else if (opt[1] == 1 && cmd[i])
		return (delete_history_offset(&(s->input->history), cmd[i], len_h, 0));
	else
		return (error_history(3));
	return (0);
}

int			do_history(t_input *input, t_env **env, t_var **var, char **cmd)
{
	int				len_h;
	int				opt[2];
	t_signal_var	*s;

	(void)env;
	(void)var;
	(void)input;
	s = singleton();
	len_h = history_len(&(s->input->history));
	if (ft_tablen(cmd) == 1)
		print_history(&(s->input->history), ft_nbrlen(len_h));
	else
		return (parse_history(s, cmd, opt, len_h));
	return (0);
}
