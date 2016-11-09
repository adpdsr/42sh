/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adu-pelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/25 09:10:57 by adu-pelo          #+#    #+#             */
/*   Updated: 2016/07/25 09:10:58 by adu-pelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lineedit.h>

char	*get_history_line(t_his **head, char *cmd)
{
	t_his *tmp;

	tmp = *head;
	while (tmp->next && tmp->select == 0)
		tmp = tmp->next;
	if (tmp->listed == 1)
		return (tmp->cmd);
	else
		return (cmd);
}

void	select_history_up(t_his *his)
{
	t_his *tmp;

	tmp = his;
	while (tmp->next && tmp->select == 0)
		tmp = tmp->next;
	tmp->select = 0;
	if (tmp->prev)
	{
		tmp = tmp->prev;
		while (tmp)
		{
			if (tmp->listed == 1)
			{
				tmp->select = 1;
				break ;
			}
			tmp = tmp->prev;
		}
	}
	else
		tmp->select = 1;
}

void	select_history_down(t_his *his)
{
	t_his *tmp;
	t_his *mem;

	tmp = his;
	while (tmp->next && tmp->select == 0)
		tmp = tmp->next;
	tmp->select = 0;
	if (tmp->next)
	{
		mem = tmp;
		while (tmp->next)
		{
			tmp = tmp->next;
			if (tmp->listed == 1 && (tmp->select = 1))
				break ;
		}
		if (tmp->select == 0)
			mem->select = 1;
	}
	else
	{
		tmp->select = 1;
	}
}

void	set_selection(t_his *tmp)
{
	while (tmp->next)
	{
		tmp->listed = 1;
		tmp->select = 0;
		tmp = tmp->next;
	}
	tmp->listed = 1;
	tmp->select = 1;
}

void	set_history(t_his *his, char *cmd)
{
	t_his *tmp;

	if (ft_strlen(cmd) && (tmp = his))
	{
		tmp->select = 0;
		while (tmp->next)
		{
			if (!ft_strncmp(tmp->cmd, cmd, ft_strlen(cmd)))
				tmp->listed = 1;
			else
				tmp->listed = 0;
			tmp = tmp->next;
			tmp->select = 0;
		}
		if (!ft_strncmp(tmp->cmd, cmd, ft_strlen(cmd)))
			tmp->listed = 1;
		else
			tmp->listed = 0;
		while (tmp->prev && tmp->listed == 0)
			tmp = tmp->prev;
		if (tmp->listed == 1)
			tmp->select = 1;
	}
	else if ((tmp = his))
		set_selection(tmp);
}
