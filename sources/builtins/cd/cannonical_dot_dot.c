/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cannonical_dot_dot.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fviolin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/09 11:49:47 by fviolin           #+#    #+#             */
/*   Updated: 2016/08/24 13:47:56 by gwells           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"
#include "builtins.h"

static char		*sub_divise_dotdot(char *path, int start, int end)
{
	char	*ret;
	char	*s1;
	char	*s2;

	s1 = ft_strsub(path, 0, start);
	s2 = ft_strsub(path, end, ft_strlen(path) - 1);
	ret = ft_strjoin(s1, s2);
	free(s1);
	free(s2);
	if (!ft_strcmp("", ret))
	{
		free(ret);
		ret = ft_strdup("/");
	}
	return (ret);
}

static void		go_to_slash(char *path, char *pos, int *i)
{
	int slash;

	*i = pos - path;
	slash = 0;
	while (slash != 2 && *i >= 0)
	{
		if (path[*i] == '/')
			slash++;
		(*i)--;
	}
}

char			*apply_posix_dotdot(char *path)
{
	char	*pos;
	int		i;
	char	*ret;

	ret = NULL;
	if ((pos = ft_strstr(path, "/..")))
	{
		if (!is_dir(path))
			return (path);
		if (pos != path)
		{
			go_to_slash(path, pos, &i);
			ret = sub_divise_dotdot(path, i + 1, pos - path + 3);
			free(path);
		}
		else
		{
			free(path);
			ret = ft_strdup("/");
		}
	}
	if (ret == NULL)
		return (path);
	else
		return (apply_posix_dotdot(ret));
}
