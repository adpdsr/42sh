/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwells <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/31 22:17:36 by gwells            #+#    #+#             */
/*   Updated: 2016/07/31 22:17:48 by gwells           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>
#include <builtins.h>

char		*get_dollar(char *str, t_env *head)
{
	char			*content;
	char			*var_name;
	char			*tmp;
	t_env			*cur;

	content = NULL;
	cur = head;
	tmp = ft_strsupress_at(str, 0);
	var_name = ft_append_char(tmp, '=');
	free(tmp);
	while (cur)
	{
		if (!ft_strcmp(var_name, cur->name))
		{
			content = ft_strdup(cur->content);
			break ;
		}
		cur = cur->next;
	}
	ft_strdel(&var_name);
	return (content);
}
