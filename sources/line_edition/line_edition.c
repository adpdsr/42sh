/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_edition.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fviolin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/28 16:42:27 by fviolin           #+#    #+#             */
/*   Updated: 2016/09/08 20:48:01 by adu-pelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lineedit.h>
#include <builtins.h>

static void			while1_event(t_event *event, int sub)
{
	int		i;

	i = 0;
	while (i != WHILE1)
	{
		if (!sub && !ft_memcmp(event->buffer,
					(void*)&(event->move[i]), sizeof(int)))
			(*(event->w1ptrfunc)[i])(event);
		if (sub && !ft_memcmp(event->buffer,
					(void*)&(event->move[i]), sizeof(int))
						&& i != 12 && i != 13)
			(*(event->w1ptrfunc)[i])(event);
		i++;
	}
}

static void			quit(t_all *all)
{
	t_signal_var	*s;
	char			**cmd;

	s = singleton();
	cmd = ft_memalloc_fail(sizeof(char *) * 3);
	cmd[0] = ft_strdup("exit");
	cmd[1] = ft_strdup("130");
	cmd[2] = NULL;
	ft_putendl_fd("exit", 2);
	use_cap("ei");
	use_cap("ke");
	ft_freetab(all->paths);
	ft_freetab(all->env_tab);
	do_exit(s->input, &s->env, &all->var, cmd);
}

static void			handle_char(char c)
{
	t_signal_var	*s;
	char			*tmp;

	s = singleton();
	tmp = insert_at(s->input->cmd_line, c);
	free(s->input->cmd_line);
	s->input->cmd_line = tmp;
}

static void			line_edition_norme(char *buffer, t_event *event)
{
	t_signal_var	*s;

	s = singleton();
	if (ft_memcmp(buffer, (void*)&(event->move[12]), sizeof(int))
	&& ft_memcmp(buffer, (void*)&(event->move[13]), sizeof(int)) &&\
	ft_cntc(s->input->cmd_line, '\n') == 0)
		s->input->is_h = 0;
	if (ft_isprint(buffer[0]) && ft_strlen(buffer) == 1 &&\
	ft_strlen(s->input->cmd_line) < 600 &&
	ft_cntc(s->input->cmd_line, '\n') == 0)
		handle_char(buffer[0]);
}

void				line_edition(t_event *event, t_all *all, int sub)
{
	t_signal_var	*s;
	char			*buffer;

	buffer = event->buffer;
	s = singleton();
	while (42)
	{
		buffer = line_edit1(sub, buffer);
		if (ft_cntc(s->input->cmd_line, '\n') == 0 || !ft_memcmp(buffer,\
		(void*)&(event->move[12]), sizeof(int)) || !ft_memcmp(buffer, \
		(void*)&(event->move[13]), sizeof(int)))
			while1_event(event, sub);
		line_edition_norme(buffer, event);
		if (ft_strlen(s->input->cmd_line) == 0 &&\
			buffer[0] == T_QUIT && buffer[1] == 0)
		{
			if (!sub)
				quit(all);
			else
				return ;
		}
		if (buffer[0] == T_ENTER && buffer[1] == 0)
			break ;
	}
}
