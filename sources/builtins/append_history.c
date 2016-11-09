/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append_history.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fviolin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/28 16:08:35 by fviolin           #+#    #+#             */
/*   Updated: 2016/09/08 11:29:15 by adu-pelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>
#include <builtins.h>
#include <lineedit.h>

static void			append_file(t_his *his, char *histpath)
{
	int				fd;
	t_his			*tmp;
	char			*tmp2;
	int				len;

	tmp = his;
	if ((fd = open(histpath, O_WRONLY | O_APPEND)) > 0)
	{
		while (tmp)
		{
			if (tmp->end == 0)
			{
				len = ft_strlen(tmp->cmd);
				tmp2 = ft_strjoin(tmp->cmd, "\n");
				write(fd, tmp2, len + 1);
				ft_strdel(&tmp2);
			}
			tmp = tmp->next;
		}
		close(fd);
	}
	else
		ft_error("42sh: history: open history file failed", 1);
}

static void			create_new_file(t_his *his, char *histpath, int nb_del)
{
	int				j;
	int				fd;
	char			*tmp;
	char			**save;

	j = 0;
	tmp = NULL;
	save = tab_from_file(his, histpath, nb_del);
	if ((fd = open(histpath, O_WRONLY | O_TRUNC)) > 0)
	{
		while (save && save[j])
		{
			tmp = ft_strjoin(save[j], "\n");
			write(fd, tmp, ft_strlen(save[j]) + 1);
			free(tmp);
			j++;
		}
		close(fd);
	}
	else
		ft_error("42sh: history: open history file failed", 1);
	ft_freetab(save);
}

static char			*good_path(t_env *env)
{
	char			*histpath;
	char			*tmp;
	t_signal_var	*s;

	s = singleton();
	histpath = get_node_content(env, "HISTFILE=");
	if (!histpath)
		histpath = ft_strdup(HPATH);
	if (!ft_strcmp(histpath, HPATH))
	{
		tmp = ft_strjoin(s->abs_path, histpath);
		free(histpath);
		histpath = tmp;
	}
	return (histpath);
}

void				append_history(t_his *his, t_env *env)
{
	int				nb;
	int				histsize;
	int				hfilelen;
	char			*histpath;

	histpath = good_path(env);
	histsize = get_histsize(env);
	hfilelen = get_filelen(histpath);
	nb = get_nbcopy(his, hfilelen);
	if ((histsize - nb) >= 0)
		append_file(his, histpath);
	else
		create_new_file(his, histpath, nb - histsize);
	free(histpath);
}
