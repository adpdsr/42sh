/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history_tools2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwells <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/31 21:35:23 by gwells            #+#    #+#             */
/*   Updated: 2016/09/08 11:29:12 by adu-pelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>
#include <builtins.h>
#include <lineedit.h>

static int	list_size2(t_his *his)
{
	int		i;
	t_his	*tmp;

	i = 0;
	tmp = his;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

static char	**cpy_file_content(t_his *tmp, int fd, int nb_del)
{
	int		i;
	int		j;
	char	*line;
	char	**ret;

	i = 0;
	j = -1;
	line = NULL;
	ret = ft_memalloc_fail(sizeof(char*) *\
	(ft_nbrline(fd) + list_size2(tmp) + 1));
	while (get_next_line(fd, &line) > 0)
	{
		if (i >= nb_del)
			ret[++j] = ft_strdup(line);
		ft_strdel(&line);
		i++;
	}
	while (tmp)
	{
		if (tmp->end == 0)
			ret[++j] = ft_strdup(tmp->cmd);
		tmp = tmp->next;
	}
	ret[++j] = NULL;
	return (ret);
}

char		**tab_from_file(t_his *his, char *histpath, int nb_del)
{
	int		fd;
	t_his	*tmp;
	char	**ret;

	tmp = his;
	ret = NULL;
	if ((fd = open(histpath, O_RDWR)) > 0)
	{
		ret = cpy_file_content(tmp, fd, nb_del);
		close(fd);
	}
	else
		ft_error("42sh: history: open history file failed", 1);
	return (ret);
}
