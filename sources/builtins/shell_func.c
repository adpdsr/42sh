/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fviolin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/28 16:10:37 by fviolin           #+#    #+#             */
/*   Updated: 2016/09/07 11:33:51 by adu-pelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>
#include <builtins.h>

int			is_shell_func(char **cmd, int i, int j)
{
	int p;
	int w;

	p = 0;
	w = 0;
	while (cmd[++j])
	{
		i = -1;
		while (cmd[j][++i])
		{
			if (p == 0 && ft_isalnum(cmd[j][i]) &&
					(cmd[j][i + 1] == '\0' || cmd[j][i + 1] == '('))
				w++;
			if ((cmd[j][i] == '(' && w == 1) ||
					(p == 1 && cmd[j][i] == ')') ||
					(p == 2 && cmd[j][i] == '{') ||
					(p == 3 && cmd[j][i] == '}'))
				p++;
		}
	}
	if (p == 4 && w == 1)
		return (1);
	return (0);
}

int			parse_split_norme1(t_var *cur, char **sp)
{
	int is_in;

	is_in = 1;
	ft_strdel(&cur->content);
	if (sp[1])
		cur->content = ft_strdup(sp[1]);
	else
		cur->content = NULL;
	return (is_in);
}

int			parse_split_norme2(t_var *cur, char **sp, char *fname)
{
	if (!ft_strcmp(cur->name, fname))
	{
		ft_strdel(&cur->content);
		cur->content = func_content(sp[0]);
	}
	return (1);
}

static int	parse_split(t_var *cur, char **sp, int is_f, int is_in)
{
	char	*fname;
	char	*tmp;
	char	*tmp2;

	tmp = ft_strjoin(sp[0], "=");
	fname = func_name(sp[0]);
	tmp2 = ft_strjoin(fname, "=");
	if (!is_f && !ft_strcmp(cur->name, sp[0]))
		is_in = 1;
	else if (!is_f && !ft_strcmp(cur->name, tmp))
		is_in = parse_split_norme1(cur, sp);
	else if (is_f && !ft_strcmp(cur->name, tmp2))
		is_in = 1;
	else if (is_f && !ft_strcmp(cur->name, fname))
		is_in = parse_split_norme2(cur, sp, fname);
	free(tmp);
	free(tmp2);
	free(fname);
	return (is_in);
}

void		fill_var(t_var **head, char *cmd, int exp, int is_f)
{
	int		is_in;
	char	**split;
	t_var	*cur;

	is_in = 0;
	cur = *head;
	split = ft_strsplit(cmd, '=');
	if (cur)
	{
		while (cur)
		{
			is_in = parse_split(cur, split, is_f, is_in);
			cur = cur->next;
		}
	}
	if (!is_in)
		var_push_back(head, var_new_node(cmd, exp, is_f));
	ft_freetab(split);
}
