/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cannonical.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fviolin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/09 11:52:50 by fviolin           #+#    #+#             */
/*   Updated: 2016/08/09 20:34:52 by fviolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"
#include "builtins.h"

char		*del_last_point(char *path)
{
	int		len;
	char	*ret;
	char	*tmp;

	len = ft_strlen(path);
	if (path[len - 1] == '.' && path[len - 2] == '/')
	{
		tmp = ft_strsupress_at(path, len - 1);
		if (len > 2)
		{
			ret = ft_strsupress_at(tmp, len - 2);
			free(tmp);
			return (ret);
		}
		ret = tmp;
		return (ret);
	}
	return (ft_strdup(path));
}

char		*del_last_slash(char *path)
{
	int		len;
	char	*ret;

	len = ft_strlen(path);
	if (len > 1 && path[len - 1] == '/')
		ret = ft_strsupress_at(path, len - 1);
	else
		ret = ft_strdup(path);
	return (ret);
}

char		*posix_step_a_dot(char *path)
{
	char	*pos;
	char	*ret;
	char	*tmp;

	ret = ft_strdup(path);
	while ((pos = ft_strstr(ret, "./")) && *(pos - 1) != '.')
	{
		tmp = ft_strsupress_at(ret, (size_t)(pos - ret));
		free(ret);
		ret = tmp;
	}
	return (ret);
}

static int	count_step_a_slash(char *path)
{
	int		count;
	int		i;

	count = 0;
	i = 0;
	while (path[i])
	{
		if (path[i] == '/')
		{
			i++;
			while (path[i] == '/')
			{
				count++;
				i++;
			}
		}
		if (path[i])
			i++;
	}
	return (count);
}

char		*posix_step_a_slash(char *path)
{
	char	*ret;
	int		i;
	int		count;

	i = 0;
	count = 0;
	ret = ft_memalloc_fail(ft_strlen(path) - count_step_a_slash(path) + 1);
	while (path[i])
	{
		if (path[i] == '/')
		{
			ret[count] = path[i];
			count++;
			i++;
			while (path[i] == '/')
				i++;
		}
		ret[count] = path[i];
		count++;
		if (path[i])
			i++;
	}
	return (ret);
}
