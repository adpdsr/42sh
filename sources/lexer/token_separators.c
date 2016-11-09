/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_separators.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adu-pelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/24 20:22:45 by adu-pelo          #+#    #+#             */
/*   Updated: 2016/07/25 15:10:56 by fviolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>
#include <processes.h>

int		is_separator(char c)
{
	return (c == '>' || c == '<' || c == '&' || c == '|');
}

int		is_and(char *str, int i)
{
	if (str[i + 1] != '&')
		return (1);
	return (2);
}

int		is_pipe(char *str, int i)
{
	if (str[i + 1] != '|')
		return (1);
	return (2);
}

int		is_quote(char *str, int i)
{
	int start;

	start = i;
	while (str[i + 1] != '\'')
		i++;
	return (i - start + 2);
}

int		is_dquote(char *str, int i)
{
	int	start;

	start = i;
	while (str[i + 1] != '\"')
		i++;
	return (i - start + 2);
}
