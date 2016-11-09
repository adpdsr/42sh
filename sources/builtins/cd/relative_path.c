/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   relative_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fviolin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/09 11:49:06 by fviolin           #+#    #+#             */
/*   Updated: 2016/08/09 11:49:31 by fviolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"
#include "builtins.h"

char		*pwd_handle(t_env *env, char *cmd, int opt)
{
	char	*pwd;
	char	*ret;
	char	link[PATH_MAX_SIZE];

	ft_bzero(link, PATH_MAX_SIZE);
	pwd = get_node_content(env, "PWD=");
	ret = NULL;
	if (pwd)
	{
		if (readlink(pwd, link, PATH_MAX_SIZE) > -1 && opt)
			ret = path_join(link, cmd);
		else
			ret = path_join(pwd, cmd);
		free(pwd);
	}
	if (is_dir(ret))
		return (ret);
	free(ret);
	return (NULL);
}

char		*cd_path_handle(t_env *env, char *cmd, int i)
{
	char	*node;
	char	**paths;
	char	*new_path;
	char	*ret;

	if (!(node = get_node_content(env, "CDPATH=")))
		return (NULL);
	paths = ft_strsplit(node, ':');
	ret = NULL;
	while (paths[i])
	{
		new_path = path_join(paths[i], cmd);
		if (is_dir(new_path))
		{
			ret = ft_strdup(new_path);
			free(new_path);
			break ;
		}
		free(new_path);
		i++;
	}
	ft_freetab(paths);
	free(node);
	return (ret);
}
