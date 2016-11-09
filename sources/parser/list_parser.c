/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fviolin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/28 15:50:48 by fviolin           #+#    #+#             */
/*   Updated: 2016/08/24 14:14:04 by gwells           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>
#include <processes.h>

void				free_parser_list(t_parser **head)
{
	t_parser	*next;

	while (*head)
	{
		next = (*head)->next;
		ft_freetab((*head)->content);
		free(*head);
		*head = next;
	}
}

static void			parser_push_back(t_parser **head, t_parser *new)
{
	t_parser *cur;

	if (!*head)
		*head = new;
	else
	{
		cur = *head;
		while (cur->next)
			cur = cur->next;
		cur->next = new;
	}
}

static t_parser		*parser_create_node(t_lexer *list_lex, int token)
{
	t_parser	*new;
	int			i;

	i = 0;
	new = ft_memalloc_fail(sizeof(t_parser));
	new->content = ft_memalloc_fail(sizeof(char *)
		* (ft_tablen(list_lex->cmd) + 1));
	while (list_lex->cmd[i])
	{
		new->content[i] = ft_strdup(list_lex->cmd[i]);
		i++;
	}
	new->content[i] = NULL;
	new->token = token;
	new->r_stdin = 0;
	new->r_stdout = 1;
	new->r_shutout_in = 0;
	new->r_shutout_out = 0;
	new->next = NULL;
	return (new);
}

t_parser			*fill_parser(t_parser *list, t_lexer *list_lex, int token)
{
	parser_push_back(&list, parser_create_node(list_lex, token));
	return (list);
}
