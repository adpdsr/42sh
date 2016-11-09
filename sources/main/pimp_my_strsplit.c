/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit_sh.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fviolin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/28 15:46:11 by fviolin           #+#    #+#             */
/*   Updated: 2016/09/08 12:03:36 by fviolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>
#include <lineedit.h>

static char		*append_word(t_inhib *line, int start, int end)
{
	int		i;
	int		j;
	char	*ret;

	i = start;
	j = 0;
	ret = ft_memalloc_fail((end - start + 1));
	while (i != end)
	{
		ret[j] = line[i].c;
		i++;
		j++;
	}
	return (ret);
}

static char		**split_loop(t_inhib *line, int i, int start, int end)
{
	int		count;
	char	**ret;
	int		nb;

	count = 0;
	nb = count_semicolon_active(line);
	ret = ft_memalloc_fail(sizeof(char *) * (nb + 1));
	while (line[i].c)
	{
		while (line[i].c && (line[i].c != ';' || !line[i].active))
		{
			end++;
			i++;
		}
		end++;
		ret[count] = append_word(line, start, end - 1);
		start = end;
		if (line[i].c)
			i++;
		count++;
	}
	return (ret);
}

static char		**handle_semicolon(t_inhib *line)
{
	int		i;
	int		end;
	int		start;
	char	**ret;

	i = 0;
	end = 0;
	start = 0;
	if (line[i].c && line[i].c == ';')
	{
		i++;
		start = 1;
		end++;
	}
	ret = split_loop(line, i, start, end);
	return (ret);
}

char			**ft_strsplit_inhib(void)
{
	t_signal_var	*s;
	t_inhib			*line;
	char			**ret;
	char			*bang;

	s = singleton();
	bang = translate_excla(s->input->cmd_line, NULL, NULL);
	line = init_inhib_line(bang);
	free(bang);
	active_quotes(line);
	active_bslash(line);
	if (!check_semicolon(line))
	{
		free(line);
		return (NULL);
	}
	ret = handle_semicolon(line);
	free(line);
	return (ret);
}
