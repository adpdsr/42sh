/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwells <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/02 15:37:31 by gwells            #+#    #+#             */
/*   Updated: 2016/09/07 12:37:51 by gwells           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lineedit.h"

t_inhib			*newline_append(char *str)
{
	t_inhib			*line;
	char			*join;
	char			*tmp;

	join = ft_strdup(str);
	line = init_inhib_line(str);
	active_quotes(line);
	active_bslash(line);
	if (check_inhib_bslash(str, 1) || check_inhib(line) != 0)
	{
		tmp = ft_strjoin(join, "\n");
		free(join);
		join = tmp;
	}
	free(line);
	line = init_inhib_line(join);
	free(join);
	active_quotes(line);
	active_bslash(line);
	return (line);
}

t_inhib			*newline_append2(char *str)
{
	t_inhib			*line;
	char			*join;
	char			*tmp;

	join = ft_strdup(str);
	line = init_inhib_line(str);
	active_quotes(line);
	active_bslash(line);
	tmp = ft_strjoin(join, "\n");
	free(join);
	join = tmp;
	free(line);
	line = init_inhib_line(join);
	free(join);
	active_quotes(line);
	active_bslash(line);
	return (line);
}

char			*save_str(t_inhib *line)
{
	char			*ret;
	int				i;

	i = 0;
	ret = ft_memalloc_fail(sizeof(char) * (line_len(line, 1) + 1));
	while (line[i].c)
	{
		ret[i] = line[i].c;
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

static t_inhib	*gnl_while(t_inhib *gnl, char *save, char *str, char *join)
{
	while (!gnl || check_inhib(gnl) != 0 || check_inhib_bslash(str, 1))
	{
		if (gnl)
		{
			ft_strdel(&save);
			save = save_str(gnl);
		}
		free(gnl);
		gnl = NULL;
		ft_strdel(&join);
		ft_strdel(&str);
		ft_putstr("$> ");
		if (get_next_line(0, &str) < 1)
		{
			ft_putendl("exit");
			ft_strdel(&str);
			break ;
		}
		join = ft_strjoin(save, str);
		gnl = newline_append(join);
	}
	free(join);
	ft_strdel(&save);
	ft_strdel(&str);
	return (gnl);
}

void			gnl(char *str, char *save)
{
	t_signal_var	*s;
	t_inhib			*gnl;
	char			*join;

	s = singleton();
	gnl = NULL;
	join = NULL;
	save = save_str(s->line);
	gnl = gnl_while(gnl, save, str, join);
	free(str);
	free(join);
	free(s->line);
	s->line = gnl;
}
