/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers_translate_varname.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fviolin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/06 16:01:31 by fviolin           #+#    #+#             */
/*   Updated: 2016/09/08 10:59:37 by fviolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lineedit.h>
#include <builtins.h>

int		if_dollar_translate(t_inhib *line, int count)
{
	int	i;

	i = 0;
	while (line[i].c && count)
	{
		if (line[i].c == '$')
			count--;
		i++;
	}
	if (line[i - 1].active)
		return (1);
	return (0);
}

char	*return_min_value(char *str1, char *str2)
{
	if (str1 < str2 && str1 != NULL)
		return (str1);
	else if (str2 < str1 && str2 != NULL)
		return (str2);
	if (!str1 && str2)
		return (str2);
	return (str1);
}

char	*return_min_str(char **splitted_cmd)
{
	char	*tmp;
	char	*tmp2;
	char	*res;

	tmp = ft_strchr(*splitted_cmd, 127);
	tmp2 = ft_strpbrk2(*splitted_cmd, " \n\\\"\'");
	res = return_min_value(tmp, tmp2);
	if (res == NULL)
		return (ft_strpbrk2((*splitted_cmd + 1), "$"));
	tmp = ft_strpbrk2((*splitted_cmd + 1), "$");
	return (return_min_value(tmp, res));
}
