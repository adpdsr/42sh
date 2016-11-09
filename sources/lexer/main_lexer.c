/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_lexer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fviolin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/28 16:40:56 by fviolin           #+#    #+#             */
/*   Updated: 2016/09/08 18:01:55 by gwells           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>
#include <processes.h>
#include <lineedit.h>
#include <builtins.h>

static int		get_string_len(t_inhib *line, char *str, int i, int len)
{
	int j;

	j = 0;
	while (str[i] && (!is_separator(str[i]) || !line[i].active))
	{
		if (ft_isdigit(str[i]) && ft_isspace(str[i - 1]))
		{
			j = i;
			while (str[j] && ft_isdigit(str[j]))
				j++;
			if (str[j] == '>' || str[j] == '<')
				return (len);
		}
		len++;
		i++;
	}
	return (len);
}

static int		get_token_len(t_inhib *line, char *str, int i)
{
	int len;

	len = 0;
	if (ft_isdigit(str[i]))
		len = is_agreg_redir(str, i);
	if (is_separator(str[i]) && line[i].active)
	{
		if (str[i] == '>')
			len = is_greater_redir(str, i);
		else if (str[i] == '<')
			len = is_lesser_redir(str, i);
		else if (str[i] == '&')
			len = is_and(str, i);
		else if (str[i] == '|')
			len = is_pipe(str, i);
	}
	else
		len = get_string_len(line, str, i, len);
	return (len);
}

static int		get_str_len(t_inhib *line, t_lexer *list, char *input, int i)
{
	int len;

	len = get_token_len(line, input, i);
	if (len == -1)
	{
		free_lexer_list(&list);
		free(line);
		return (-1);
	}
	return (len);
}

t_lexer			*do_lexer(t_lexer *list, char *input)
{
	int		i;
	int		len;
	int		start;
	char	*tmp;
	t_inhib *line;

	i = 0;
	tmp = NULL;
	line = init_inhib_line(input);
	active_quotes(line);
	active_bslash(line);
	while (input[i])
	{
		start = i;
		if ((len = get_str_len(line, list, input, i)) == -1)
			return (NULL);
		tmp = ft_strsub(input, start, len);
		list = fill_lexer(list, tmp, is_active_token(line, start, len));
		ft_strdel(&tmp);
		i += len;
		if (i >= (int)ft_strlen(input))
			break ;
	}
	free(line);
	return (list);
}

void			multi_cmd(t_all *all, int i)
{
	t_lexer			*list;
	t_parser		*processes;
	char			**split_input;

	if (!(split_input = ft_strsplit_inhib()))
	{
		ft_putendl_fd("42sh: parse error", 2);
		return ;
	}
	while (split_input[i])
	{
		list = do_lexer(NULL, split_input[i]);
		if (!list)
			break ;
		processes = do_parsing(all, list, NULL);
		free_lexer_list(&list);
		if (!processes)
			break ;
		execute_manager(all, processes);
		free_parser_list(&processes);
		i++;
	}
	h_insert();
	ft_freetab(split_input);
}
