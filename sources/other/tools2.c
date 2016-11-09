/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fviolin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/28 15:49:19 by fviolin           #+#    #+#             */
/*   Updated: 2016/07/31 23:28:38 by gwells           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

int			ft_poutchar(int c)
{
	return (write(2, &c, 1));
}

char		*get_cmd_path(char *cmd, char **paths)
{
	struct dirent	*ret;
	DIR				*dir;

	if (cmd && paths && *paths)
	{
		while (*paths)
		{
			if ((dir = opendir(*paths)))
			{
				while ((ret = readdir(dir)))
					if (!ft_strcmp(ret->d_name, cmd))
					{
						closedir(dir);
						return (ft_strdup(*paths));
					}
				closedir(dir);
			}
			paths++;
		}
	}
	return (NULL);
}

char		*add_full_path(char **cmd, char *path)
{
	char *tmp;

	tmp = NULL;
	if (path)
		tmp = ft_strjoin(path, "/");
	path = ft_strjoin(tmp, cmd[0]);
	ft_strdel(&tmp);
	return (path);
}

static int	get_list_len(t_env *list)
{
	int count;

	count = 0;
	while (list)
	{
		count++;
		list = list->next;
	}
	return (count);
}

char		**list_in_tab(t_env *list)
{
	char	**env_cpy;
	char	*str;
	int		i;
	int		len;
	char	*tmp;

	i = 0;
	len = get_list_len(list);
	if (!(env_cpy = (char **)malloc(sizeof(char *) * (len + 1))))
		return (NULL);
	while (list)
	{
		str = ft_strdup(list->name);
		if (list->content)
			tmp = ft_strjoin(str, list->content);
		env_cpy[i] = tmp;
		i++;
		free(str);
		list = list->next;
	}
	env_cpy[i] = NULL;
	return (env_cpy);
}
