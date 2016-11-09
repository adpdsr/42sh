/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eport_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwells <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/31 22:22:09 by gwells            #+#    #+#             */
/*   Updated: 2016/07/31 22:24:30 by gwells           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>
#include <builtins.h>

static char	**format_from_list(t_var **head, char *cmd)
{
	t_var	*tmp;
	char	**res;
	char	*tmp2;

	res = NULL;
	tmp = *head;
	if (!(res = (char **)malloc(sizeof(char *) * 4)))
		ft_error("export: malloc failed", 1);
	tmp2 = ft_strjoin(cmd, "=");
	while (tmp)
	{
		if (!ft_strcmp(tmp->name, tmp2))
		{
			tmp->exported = 1;
			res[0] = ft_strdup("setenv");
			res[1] = ft_strsub(tmp->name, 0, ft_strlen(tmp->name) - 1);
			res[2] = ft_strdup(tmp->content);
			res[3] = NULL;
			free(tmp2);
			return (res);
		}
		tmp = tmp->next;
	}
	free(tmp2);
	return (NULL);
}

static char	**format_from_arg(char *cmd)
{
	char	**res;
	char	**data;

	data = ft_strsplit(cmd, '=');
	if (!(res = (char **)malloc(sizeof(char *) * 4)))
		ft_error("export: malloc failed", 1);
	res[0] = ft_strdup("setenv");
	res[1] = ft_strdup(data[0]);
	if (data[1])
	{
		res[2] = ft_strdup(data[1]);
		res[3] = NULL;
	}
	else
		res[2] = NULL;
	ft_freetab(data);
	return (res);
}

char		**read_export_args_norme(char **res, char *cmd, t_var **v)
{
	if (ft_cntc(cmd, '=') == 1)
	{
		res = format_from_arg(cmd);
		fill_var(v, cmd, 1, 0);
	}
	else
		res = format_from_list(v, cmd);
	return (res);
}
