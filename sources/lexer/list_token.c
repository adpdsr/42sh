/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_token.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fviolin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/28 16:28:56 by fviolin           #+#    #+#             */
/*   Updated: 2016/09/08 19:34:35 by adu-pelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>
#include <processes.h>
#include "lineedit.h"

static	void		lexer_push_back(t_lexer **head, t_lexer *new)
{
	t_lexer *cur;

	if (!*head)
		*head = new;
	else
	{
		cur = *head;
		while (cur->next)
			cur = cur->next;
		cur->next = new;
		new->prev = cur;
	}
}

static int			clear_inhib_line(t_lexer *new, t_inhib **line)
{
	char	*translated_line;
	char	*raw_line;

	supress_bslash_space(*line);
	raw_line = save_str(*line);
	translated_line = dollar_translate(*line, raw_line);
	free(*line);
	*line = init_inhib_line(translated_line);
	active_quotes(*line);
	active_bslash(*line);
	free(new->content);
	new->content = inhib_to_input_cmd_line(*line);
	free(translated_line);
	free(raw_line);
	new->cmd = ft_strsplit_ws(new->content);
	return (0);
}

static	t_lexer		*lexer_create_node(char *str, int token)
{
	t_lexer *new;
	t_inhib	*line;
	int		i;

	i = 0;
	new = ft_memalloc_fail(sizeof(t_lexer));
	new->content = ft_strdup(str);
	line = newline_append(new->content);
	clear_inhib_line(new, &line);
	while (new->cmd[i])
	{
		recover_space(new->cmd[i]);
		i++;
	}
	new->token = token;
	new->next = NULL;
	new->prev = NULL;
	free(line);
	return (new);
}

int					get_token_id(char *str)
{
	if (!ft_strcmp(str, ">>"))
		return (DGREAT);
	else if (!ft_strcmp(str, "<<"))
		return (DLESS);
	else if (ft_cntc(str, '>') == 1)
		return (GREAT);
	else if (ft_cntc(str, '<') == 1)
		return (LESS);
	else if (ft_cntc(str, '>') == 2)
		return (DGREAT);
	else if (ft_cntc(str, '<') == 2)
		return (DLESS);
	else if (!ft_strcmp(str, "|"))
		return (PIPE);
	else if (!ft_strcmp(str, "||"))
		return (OR);
	else if (!ft_strcmp(str, "&&"))
		return (AND);
	else
		return (CMD);
	return (0);
}

t_lexer				*fill_lexer(t_lexer *list, char *str, int flag)
{
	int			id;
	t_lexer		*node;

	if (flag)
		id = get_token_id(str);
	else
		id = CMD;
	node = lexer_create_node(str, id);
	if (node)
		lexer_push_back(&list, node);
	return (list);
}
