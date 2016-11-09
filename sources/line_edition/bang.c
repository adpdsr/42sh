/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bang.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adu-pelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/31 15:55:25 by adu-pelo          #+#    #+#             */
/*   Updated: 2016/09/08 20:23:45 by adu-pelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "processes.h"
#include "lineedit.h"

static char	*get_last_history_line(t_his *tmp)
{
	if (!tmp)
		return (NULL);
	while (tmp->next)
		tmp = tmp->next;
	return (ft_strdup(tmp->prev->cmd));
}

static char	*get_last_history_word(t_his *tmp)
{
	int i;

	while (tmp->next)
		tmp = tmp->next;
	if (tmp)
	{
		i = ft_strlen(tmp->cmd);
		while (i >= 0)
		{
			if (ft_isspace(tmp->cmd[i]))
			{
				return (ft_strsub(tmp->cmd, i + 1, \
					ft_strlen(tmp->cmd) - i));
			}
			i--;
		}
		return (ft_strdup(tmp->cmd));
	}
	return (NULL);
}

static char	*get_last_history_sub(t_his *tmp)
{
	int i;

	while (tmp->next)
		tmp = tmp->next;
	if (tmp)
	{
		i = 0;
		while (tmp->cmd[i])
		{
			if (ft_isspace(tmp->cmd[i]))
			{
				while (ft_isspace(tmp->cmd[i]))
					i++;
				return (ft_strsub(tmp->cmd, i, ft_strlen(tmp->cmd) - i));
			}
			i++;
		}
		return (ft_strdup(tmp->cmd));
	}
	return (NULL);
}

static char	*get_last_history_match(t_his *tmp, char *his_cmd)
{
	char	*res;

	while (tmp->next)
		tmp = tmp->next;
	while (tmp && tmp->prev)
	{
		if (!ft_strncmp(his_cmd, tmp->cmd, ft_strlen(his_cmd)))
		{
			res = ft_strdup(tmp->cmd);
			return (res);
		}
		tmp = tmp->prev;
	}
	return (NULL);
}

char		*choose_option(char *parsed)
{
	char			*occ;
	char			*res;
	t_his			*his;
	t_signal_var	*s;

	occ = NULL;
	res = NULL;
	s = singleton();
	his = s->input->history;
	if (!ft_strncmp(parsed, "!", 1))
		res = get_last_history_line(his);
	else if (!ft_strncmp(parsed, "$", 1))
		res = get_last_history_word(his);
	else if (!ft_strncmp(parsed, "*", 1))
		res = get_last_history_sub(his);
	else
	{
		occ = to_search(parsed);
		res = get_last_history_match(his, occ);
		ft_strdel(&occ);
	}
	return (res);
}
