/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eol_bslash.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwells <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/02 14:59:41 by gwells            #+#    #+#             */
/*   Updated: 2016/09/08 18:00:10 by gwells           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lineedit.h"

static void		bslash_before_bslash(t_inhib *line, int *index)
{
	int					count;

	count = 0;
	(*index)++;
	while (line[*index].c == '\\')
	{
		count++;
		if (count % 2)
			line[*index].active = 0;
		(*index)++;
	}
}

static void		squote_desactivate(t_inhib *line, int *index)
{
	(*index)++;
	while (line[*index].c && (line[*index].c != '\''\
		|| !line[*index].active))
	{
		line[*index].active = 0;
		(*index)++;
	}
}

static void		duo_activate(t_inhib *line, int index, int first, int second)
{
	line[index].active = first;
	line[index - 1].active = second;
}

static void		dquote_activate(t_inhib *line, int *index)
{
	(*index)++;
	while (line[*index].c && (line[*index].c != '\"' \
		|| !line[*index].active))
	{
		if (line[*index].c == '\\')
		{
			(*index)++;
			if (line[*index].c == '\"' || line[*index].c == '\\' ||\
				line[*index].c == '$')
				duo_activate(line, *index, 0, 1);
			else if (line[*index].c == '\n')
				duo_activate(line, *index, 1, 1);
			else
				duo_activate(line, *index, 0, 0);
		}
		else if (line[*index].c != '$')
			line[*index].active = 0;
		if (line[*index].c)
			(*index)++;
	}
}

void			active_bslash(t_inhib *line)
{
	int				i;

	i = 0;
	while (line[i].c)
	{
		if (line[i].c == '\'' && line[i].active == 1)
			squote_desactivate(line, &i);
		if (line[i].c == '\"' && line[i].active == 1)
			dquote_activate(line, &i);
		if (line[i].c == '\\')
			bslash_before_bslash(line, &i);
		if (line[i].c == '$')
			line[i].active = (bslash_before(line, i)) ? 0 : 1;
		if (line[i].c == '\n')
			line[i].active = (bslash_before(line, i)) ? 1 : 0;
		if (line[i].c == ';')
			line[i].active = (bslash_before(line, i)) ? 0 : 1;
		if (line[i].c == '>' || line[i].c == '<')
			line[i].active = (bslash_before(line, i)) ? 0 : 1;
		if (line[i].c == '|')
			line[i].active = (bslash_before(line, i)) ? 0 : 1;
		if (line[i].c)
			i++;
	}
}
