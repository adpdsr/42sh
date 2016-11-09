/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwells <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/02 15:31:18 by gwells            #+#    #+#             */
/*   Updated: 2016/09/07 11:49:11 by adu-pelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lineedit.h"

int			bslash_before(t_inhib *line, int index)
{
	int				count;

	count = 0;
	while (index > 0 && line[index - 1].c == '\\')
	{
		index--;
		count++;
	}
	return (count % 2);
}

static void	until_single_quote(t_inhib *line, int *index)
{
	(*index)++;
	while (line[*index].c && line[*index].c != '\'')
	{
		if (line[*index].c == ' ')
			line[*index].c = 127;
		(*index)++;
	}
}

static void	until_double_quote(t_inhib *line, int *index)
{
	(*index)++;
	while (line[*index].c && (line[*index].c != '\"' ||\
				bslash_before(line, *index)))
	{
		if (line[*index].c == '\'' || (line[*index].c == '\"'\
			&& bslash_before(line, *index)))
			line[*index].active = 0;
		if (line[*index].c == ' ')
			line[*index].c = 127;
		(*index)++;
	}
}

void		active_quotes(t_inhib *line)
{
	int				i;

	i = 0;
	while (line[i].c)
	{
		if (line[i].c == '\'' && !bslash_before(line, i))
			until_single_quote(line, &i);
		else if (line[i].c == '\'' && bslash_before(line, i))
			line[i].active = 0;
		else if (line[i].c == '\"' && !bslash_before(line, i))
			until_double_quote(line, &i);
		else if (line[i].c == '\"' && bslash_before(line, i))
			line[i].active = 0;
		if (line[i].c)
			i++;
	}
}
