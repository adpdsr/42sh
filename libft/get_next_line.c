/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwells <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/16 18:55:58 by gwells            #+#    #+#             */
/*   Updated: 2015/02/10 11:55:55 by gwells           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

static int		lastline(char **reste, char **line)
{
	*line = ft_strdup(*reste);
	if (!(*line))
		return (-1);
	ft_strdel(reste);
	*reste = ft_strdup("");
	if (!(*reste))
		return (-1);
	return (1);
}

static int		retligne(char **reste, char **line)
{
	char		*temp;

	if (!line)
		ft_strdel(line);
	if (ft_strchr(*reste, '\n'))
	{
		*line = ft_strsub(*reste, 0, ft_strchr(*reste, '\n') - *reste);
		if (!(*line))
			return (-1);
		temp = ft_strdup(ft_strchr(*reste, '\n') + 1);
		if (!temp)
			return (-1);
		ft_strdel(reste);
		*reste = ft_strdup(temp);
		if (!(*reste))
			return (-1);
		ft_strdel(&temp);
		return (1);
	}
	else if (*reste != '\0')
		return (lastline(reste, line));
	return (0);
}

static int		retbuffer(int const fd, char **reste)
{
	char		*buffer;
	char		*temp;
	int			ret;

	buffer = NULL;
	ret = read(fd, buffer, 0);
	buffer = ft_strnew(BUFF_SIZE);
	if (!buffer)
		return (-1);
	while (!ft_strchr(*reste, '\n') && (ret = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		buffer[ret] = 0;
		temp = ft_strjoin(*reste, buffer);
		if (!temp)
			return (-1);
		ft_strdel(reste);
		*reste = ft_strdup(temp);
		if (!(*reste))
			return (-1);
		ft_strdel(&temp);
	}
	ft_strdel(&buffer);
	return (ret);
}

int				get_next_line(int const fd, char **line)
{
	static char	*reste = NULL;
	int			ret;
	int			ret2;

	if (!reste)
	{
		reste = ft_strnew(0);
		if (!reste)
			return (-1);
	}
	ret = retbuffer(fd, &reste);
	if (fd < 0 || BUFF_SIZE <= 0 || ret < 0 || !line)
		return (-1);
	if (!ret && !(*reste))
		return (0);
	ret2 = retligne(&reste, line);
	if (ret2 == -1)
		return (-1);
	if (ret2 == 0 && ret == 0)
		return (0);
	return (1);
}
