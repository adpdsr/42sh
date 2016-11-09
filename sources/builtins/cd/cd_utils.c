/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fviolin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/09 11:51:12 by fviolin           #+#    #+#             */
/*   Updated: 2016/08/09 11:51:52 by fviolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"
#include "builtins.h"

static int		end_by_slash(char *str)
{
	while (*(str + 1))
	{
		str++;
	}
	if (*str == '/')
		return (1);
	else
		return (0);
}

char			*path_join(char *base, char *cmd)
{
	char		*path;

	path = ft_memalloc_fail(ft_strlen(base) + ft_strlen(cmd) + 2);
	path = ft_strcat(path, base);
	if (!end_by_slash(base))
		path = ft_strcat(path, "/");
	path = ft_strcat(path, cmd);
	return (path);
}

int				is_dir(char *path)
{
	struct stat sb;

	ft_bzero((void*)&sb, sizeof(struct stat));
	if (!path)
		return (0);
	stat(path, &sb);
	if (!S_ISDIR(sb.st_mode))
		return (0);
	return (1);
}

int				if_absolute(char *cmd)
{
	if (cmd[0] == '/')
		return (1);
	return (0);
}

int				error(char *path)
{
	struct stat sb;

	if (!path)
	{
		ft_putendl_fd("cd : No such file or directory", 2);
		return (1);
	}
	stat(path, &sb);
	if (ft_strlen(path) > 1024)
		ft_putendl_fd("cd : Path too long", 2);
	else if (ft_strlen(ft_strrchr(path, '/')) > 255)
		ft_putendl_fd("cd : File name too long", 2);
	else if (check_file_access(path) == 127)
		ft_putendl_fd("cd : No such file or directory", 2);
	else if (!S_ISDIR(sb.st_mode))
		ft_putendl_fd("cd : Not a directory", 2);
	else if (check_file_access(path) == 126)
		ft_putendl_fd("cd : Permission Denied", 2);
	else
		return (0);
	return (1);
}
