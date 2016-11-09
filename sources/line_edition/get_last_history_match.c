/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_last_history_match.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fviolin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/28 16:47:09 by fviolin           #+#    #+#             */
/*   Updated: 2016/09/08 20:23:43 by adu-pelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "processes.h"
#include "lineedit.h"

static char	*parse(char *splitted_cmd, char *tmp, int i)
{
	char	*res;
	char	*occ;
	char	*sub;
	char	*his_element;

	res = NULL;
	his_element = NULL;
	sub = ft_strsub(splitted_cmd, i + 1, (int)ft_strlen(splitted_cmd) - i - 1);
	occ = to_search(sub);
	ft_strdel(&sub);
	his_element = choose_option(occ);
	ft_strdel(&occ);
	if (tmp && ft_strlen(tmp))
	{
		res = ft_strjoin(tmp, his_element);
		ft_strdel(&his_element);
		return (res);
	}
	return (his_element);
}

static char	*append_char(char *tmp, char c)
{
	char *res;

	res = NULL;
	res = ft_append_char(tmp, c);
	return (res);
}

static int	get_index_inc(char *splitted_cmd, char *res, int i)
{
	char *occ;
	char *sub;

	sub = ft_strsub(splitted_cmd, i + 1, (int)ft_strlen(splitted_cmd) - i - 1);
	occ = to_search(sub);
	ft_strdel(&sub);
	if (res)
	{
		i += ft_strlen(occ);
		if (splitted_cmd[i] == '!')
			i++;
	}
	ft_strdel(&occ);
	return (i);
}

char		*to_search(char *rest)
{
	int		i;
	char	*res;

	i = 0;
	while (rest[i])
	{
		if (rest[i] == '!' || rest[i] == '"' || rest[i] == ' ')
		{
			res = ft_strsub(rest, 0, i);
			return (res);
		}
		i++;
	}
	res = ft_strdup(rest);
	return (res);
}

char		*translate_excla(char *splitted_cmd, char *res, char *tmp)
{
	int	i;

	i = 0;
	while (splitted_cmd[i])
	{
		tmp = ft_strdup(res);
		ft_strdel(&res);
		if (splitted_cmd[i] == '!' && splitted_cmd[i + 1] \
				&& splitted_cmd[i + 1] != '"' && splitted_cmd[i + 1] != ' ' \
				&& check_exclamation(splitted_cmd, i) == 1)
		{
			res = parse(splitted_cmd, tmp, i);
			i = get_index_inc(splitted_cmd, res, i);
			if (!res)
				res = append_char(tmp, splitted_cmd[i]);
		}
		else
			res = append_char(tmp, splitted_cmd[i]);
		ft_strdel(&tmp);
		if (splitted_cmd[i + 1])
			i++;
		else
			break ;
	}
	return (res);
}
