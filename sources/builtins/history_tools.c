/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adu-pelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/23 18:57:02 by adu-pelo          #+#    #+#             */
/*   Updated: 2016/09/02 13:22:39 by adu-pelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>
#include <builtins.h>

int			get_histsize(t_env *env)
{
	int		histsize;
	char	*histcont;

	histcont = get_node_content(env, "HISTSIZE=");
	if (!histcont)
		histsize = 300;
	else
	{
		if (ft_isstrdigit(histcont))
			histsize = ft_atoi(histcont);
		else
			histsize = 300;
	}
	ft_strdel(&histcont);
	return (histsize);
}

int			get_filelen(char *histpath)
{
	int		fd;
	int		len;
	char	*line;

	len = 0;
	if ((fd = open(histpath, O_RDONLY)) > 0)
	{
		while ((get_next_line(fd, &line)) > 0)
		{
			ft_strdel(&line);
			len++;
		}
		close(fd);
	}
	else
		ft_error("42sh: history: open history file failed", 1);
	return (len);
}

int			get_nbcopy(t_his *his, int hfilelen)
{
	int		nb;

	nb = 0;
	if (his)
	{
		while (his)
		{
			if (his->end == 0)
				nb++;
			his = his->next;
		}
	}
	return (nb + hfilelen);
}

int			history_len(t_his **head)
{
	int		len;
	t_his	*tmp;

	len = 0;
	tmp = *head;
	while (tmp)
	{
		tmp = tmp->next;
		len++;
	}
	return (len);
}

int			delete_history(t_his **head)
{
	t_his *next;

	if (head)
	{
		while (*head)
		{
			next = (*head)->next;
			ft_strdel(&((*head)->cmd));
			free(*head);
			*head = NULL;
			*head = next;
		}
	}
	free(*head);
	*head = NULL;
	return (0);
}
