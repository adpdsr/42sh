/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fviolin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/28 16:45:27 by fviolin           #+#    #+#             */
/*   Updated: 2016/09/04 18:35:35 by fviolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lineedit.h"
#include "sh.h"

int					*init_move_tab(void)
{
	int	*ret;

	ret = ft_memalloc_fail(sizeof(int) * WHILE1);
	ret[0] = T_UP;
	ret[1] = T_DOWN;
	ret[2] = T_LEFT;
	ret[3] = T_RIGHT;
	ret[4] = T_DEL;
	ret[5] = T_HOME;
	ret[6] = T_END;
	ret[7] = T_FWORD;
	ret[8] = T_BWORD;
	ret[9] = T_VISUAL;
	ret[10] = T_SUP;
	ret[11] = T_PAST;
	ret[12] = T_HUP;
	ret[13] = T_HDOWN;
	return (ret);
}

int					*init_cmove_tab(void)
{
	int	*ret;

	ret = ft_memalloc_fail(sizeof(int) * (WHILE2));
	ret[0] = T_LEFT;
	ret[1] = T_RIGHT;
	return (ret);
}

static void			init_singleton(void)
{
	t_signal_var	*s;
	char			*tmp;

	s = singleton();
	tmp = getcwd(NULL, 200);
	s->term = NULL;
	s->abs_path = ft_strjoin(tmp, "/");
	free(tmp);
	s->input = ft_memalloc_fail(sizeof(t_input));
	s->input->cmd_line = ft_strdup("");
	s->input->cursor = (t_cursor*)ft_memalloc_fail(sizeof(t_cursor));
	s->input->cursor->y = 0;
	s->fd = fd_ioctl();
	get_winsize(s->fd);
	close(s->fd);
	s->input->cp = NULL;
	s->input->history = create_history(s->input->history, s->env);
	s->input->is_h = 0;
}

void				init_var(t_event **event)
{
	init_singleton();
	(*event) = ft_memalloc_fail(sizeof(t_event));
	setup_while1((*event)->w1ptrfunc);
	setup_while2((*event)->w2ptrfunc);
	(*event)->buffer = ft_memalloc_fail(8);
	(*event)->move = init_move_tab();
	(*event)->cmove = init_cmove_tab();
}
