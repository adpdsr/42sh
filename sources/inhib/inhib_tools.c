/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inhib_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwells <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/02 14:45:31 by gwells            #+#    #+#             */
/*   Updated: 2016/09/08 19:30:25 by adu-pelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lineedit.h"

int			count_dollars(t_inhib *line)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (line[i].c)
	{
		if (line[i].c == '$' || line[i].c == '&' || line[i].c == '|'\
			|| line[i].c == '<' || line[i].c == '>' || line[i].active)
			count++;
		i++;
	}
	return (count);
}

int			line_len(t_inhib *line, int mode)
{
	int				i;
	int				count;

	i = 0;
	count = 0;
	if (mode)
	{
		while (line[i].c)
			i++;
		return (i);
	}
	else
	{
		while (line[i].c)
		{
			if (!line[i].active)
				count++;
			i++;
		}
		return (count);
	}
}

t_inhib		*init_inhib_line(char *str)
{
	t_inhib	*line;
	int		len;
	int		i;

	i = 0;
	len = ft_strlen(str);
	line = ft_memalloc_fail(sizeof(t_inhib) * (len + 1));
	while (i != len)
	{
		line[i].c = str[i];
		if (str[i] != '\\' && str[i] != '\n' && str[i] !=\
		'\"' && str[i] != '\'' && str[i] != '$' && str[i] != ';'\
		&& str[i] != '|' && str[i] != '<' && str[i] != '>' && str[i] != '&')
			line[i].active = 0;
		else
			line[i].active = 1;
		i++;
	}
	line[i].c = '\0';
	return (line);
}

char		*inhib_to_input_cmd_line(t_inhib *line)
{
	char			*ret;
	int				i;
	int				x;

	i = 0;
	x = 0;
	ret = ft_memalloc_fail(sizeof(char) * (line_len(line, 0)\
	+ count_dollars(line) + 2));
	while (line[i].c)
	{
		if (!line[i].active || line[i].c == '$' || line[i].c == '&'\
			|| line[i].c == '<' || line[i].c == '|' || line[i].c == '>')
		{
			ret[x] = line[i].c;
			x++;
		}
		i++;
	}
	ret[x] = '\0';
	return (ret);
}
