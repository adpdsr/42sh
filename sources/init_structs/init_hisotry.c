/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_hisotry.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fviolin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/28 16:27:21 by fviolin           #+#    #+#             */
/*   Updated: 2016/07/28 16:27:23 by fviolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"
#include "lineedit.h"

static void		set_history_end(t_his **head)
{
	t_his	*tmp;

	tmp = *head;
	if (tmp->next)
	{
		while (tmp->next)
		{
			tmp->end = 1;
			tmp = tmp->next;
		}
	}
	tmp->end = 1;
}

static int		get_hfilelen(char *histpath)
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
		ft_putendl_fd("42sh: history file invalid", 2);
	return (len);
}

static char		*get_history_path(t_env *env)
{
	char	*path;

	path = NULL;
	if (!(path = get_node_content(env, "HISTFILE=")))
		path = ft_strdup(HPATH);
	return (path);
}

static t_his	*fill_history(t_env *env, t_his *his, int filelen, int fd)
{
	int		rd;
	int		histsize;
	char	*line;

	his = NULL;
	if (env)
	{
		line = get_node_content(env, "HISTSIZE=");
		histsize = ft_atoi(line);
		ft_strdel(&line);
	}
	while ((rd = get_next_line(fd, &line)) > 0)
	{
		if ((filelen - histsize) < 0)
		{
			his = his_push_back(&his, his_create_node(line));
			ft_strdel(&line);
		}
		filelen--;
	}
	if (rd < 0)
		ft_putendl_fd("42sh: history file invalid", 2);
	return (his);
}

t_his			*create_history(t_his *his, t_env *env)
{
	int		fd;
	char	*histpath;

	histpath = get_history_path(env);
	if ((fd = open(histpath, O_RDWR)) > 0)
	{
		if ((his = fill_history(env, his, get_hfilelen(histpath), fd)))
			set_history_end(&his);
		close(fd);
		free(histpath);
		return (his);
	}
	ft_putendl_fd("42sh: history file invalid", 2);
	free(histpath);
	return (NULL);
}
