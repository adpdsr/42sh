/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptrfunc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adu-pelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/25 09:12:24 by adu-pelo          #+#    #+#             */
/*   Updated: 2016/09/04 18:35:00 by fviolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lineedit.h"

void	setup_while1(t_funcwhile1 *ptrfunc)
{
	ptrfunc[UP] = &move_up;
	ptrfunc[DOWN] = &move_down;
	ptrfunc[LEFT] = &move_left;
	ptrfunc[RIGHT] = &move_right;
	ptrfunc[DEL] = &del_at;
	ptrfunc[HOME] = &home;
	ptrfunc[END] = &end;
	ptrfunc[FWORD] = &fword;
	ptrfunc[BWORD] = &bword;
	ptrfunc[CP] = &select_c;
	ptrfunc[SUP] = &del;
	ptrfunc[PAST] = &past;
	ptrfunc[HISTORY_UP] = &history_up;
	ptrfunc[HISTORY_DOWN] = &history_down;
}

void	setup_while2(t_funcwhile2 *ptrfunc)
{
	ptrfunc[CLEFT] = &smove_left;
	ptrfunc[CRIGHT] = &smove_right;
}
