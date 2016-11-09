/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adu-pelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/24 10:35:14 by adu-pelo          #+#    #+#             */
/*   Updated: 2016/07/24 11:53:49 by adu-pelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>
#include <builtins.h>

t_var	*var_new_node(char *cmd, int exp, int is_f)
{
	char	**sp;
	t_var	*new;

	sp = ft_strsplit(cmd, '=');
	new = (t_var *)ft_memalloc_fail(sizeof(t_var));
	new->name = (is_f > 0) ? func_name(sp[0]) : ft_strjoin(sp[0], "=");
	new->content = (is_f > 0) ? func_content(sp[0]) : ft_strdup(sp[1]);
	new->exported = (exp > 0) ? 1 : 0;
	new->is_func = (is_f > 0) ? 1 : 0;
	new->next = NULL;
	ft_freetab(sp);
	sp = NULL;
	return (new);
}

void	var_push_back(t_var **head, t_var *new)
{
	t_var	*cur;

	cur = *head;
	if (!*head)
		*head = new;
	else
	{
		while (cur->next)
			cur = cur->next;
		cur->next = new;
	}
}

int		check_shell_var(t_var **var, char **cmd)
{
	char	*func;

	if (ft_cntc(cmd[0], '=') == 1)
	{
		fill_var(var, cmd[0], 0, 0);
		return (0);
	}
	else if (is_shell_func(cmd, -1, -1))
	{
		func = tab_to_str(cmd);
		fill_var(var, func, 0, 1);
		ft_strdel(&func);
		return (0);
	}
	return (-1);
}
