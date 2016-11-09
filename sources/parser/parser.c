/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adu-pelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/25 09:22:06 by fviolin           #+#    #+#             */
/*   Updated: 2016/09/03 14:20:54 by gwells           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>
#include <processes.h>
#include <builtins.h>

static int		check_lexer_error(t_lexer *list)
{
	if (list->token >= 0 && list->token <= 6)
		return (-1);
	while (list->next)
		list = list->next;
	if (list->token == PIPE)
		return (-1);
	return (0);
}

t_parser		*do_parsing(t_all *all, t_lexer *list, t_parser *process)
{
	int ret;

	ret = 0;
	if (check_lexer_error(list) == -1)
		process = fill_parser(process, list, ERROR);
	else
		while (list)
		{
			if (list->token == CMD && list->next)
				process = fill_parser(process, list, list->next->token);
			if (list->token >= 1 && list->token <= 4)
				ret = manage_io_files(all, list, process, list->token);
			if (ret == -1 || ret == -2)
			{
				free_parser_list(&process);
				break ;
			}
			else if (list->token == CMD && !list->next)
				process = fill_parser(process, list, END_LIST);
			list = list->next;
		}
	return (process);
}
