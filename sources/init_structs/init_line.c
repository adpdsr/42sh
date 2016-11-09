/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adu-pelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/24 20:22:00 by adu-pelo          #+#    #+#             */
/*   Updated: 2016/07/24 20:22:01 by adu-pelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

t_line	*init_line(t_line *line, int prompt_len)
{
	line = (t_line *)malloc(sizeof(t_line));
	line->prompt_len = prompt_len;
	line->paranthesis = 0;
	line->dblquote = 0;
	line->bquote = 0;
	line->quote = 0;
	line->hook = 0;
	line->href = 0;
	line->flag = 0;
	line->brace = 0;
	line->cmd = NULL;
	line->copy = NULL;
	return (line != NULL ? line : NULL);
}
