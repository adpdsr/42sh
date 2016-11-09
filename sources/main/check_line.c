/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fviolin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/28 15:44:55 by fviolin           #+#    #+#             */
/*   Updated: 2016/09/06 16:08:52 by fviolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lineedit.h"

int					cmd_not_empty(char *s)
{
	int i;

	i = 0;
	if (s && s[i])
	{
		while (s[i])
		{
			if (s[i] != ' ' || s[i] != '\t')
				return (1);
			i++;
		}
	}
	return (0);
}

static void			check_quote_handle(char *s, int i, int \
		*in_squote, int *in_bquote)
{
	if (s[i] == '\'')
	{
		if (*in_squote == 0)
			*in_squote = 1;
		else
			*in_squote = 0;
	}
	else if (s[i] == '`')
	{
		if (*in_bquote == 0)
			*in_bquote = 1;
		else
			*in_bquote = 0;
	}
}

int					check_exclamation(char *s, int index)
{
	int				i;
	int				in_squote;
	int				in_bquote;

	i = 0;
	in_squote = 0;
	in_bquote = 0;
	if (index == (int)(ft_strlen(s) - 1))
		return (-1);
	while (s[i])
	{
		if (i == index)
		{
			if (in_squote == 0 && in_bquote == 0)
				return (1);
			else
				return (-1);
		}
		if (s[i] == '\\')
			i += 1;
		else
			check_quote_handle(s, i, &in_squote, &in_bquote);
		i++;
	}
	return (-1);
}

int					check_if_print(char *s, int index, int start, int end)
{
	int				i;

	i = start;
	while (s[i] && s[i] != '\'' && s[i] != '\"')
		i++;
	start = i;
	if (s[i])
		i++;
	while (s[i] && s[i] != s[start])
		i++;
	end = i;
	if (s[end] && index > end)
		return (check_if_print(s, index, end, 0));
	else if (index <= start || index == end)
		return (-1);
	else
		return (1);
}
