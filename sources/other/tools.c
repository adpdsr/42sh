/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fviolin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/28 15:48:55 by fviolin           #+#    #+#             */
/*   Updated: 2016/09/06 16:15:24 by fviolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"
#include "processes.h"

char	*get_var_content(char *str)
{
	char	*var_content;
	int		i;
	int		j;

	i = 0;
	j = ft_strlen(str);
	while (str[i] && str[i] != '=')
		i++;
	i += 1;
	if (i == j)
		return (ft_strdup(""));
	else
		var_content = ft_strsub(str, i, ft_strlen(str) - i);
	return (var_content);
}

char	*get_var_name(char *str)
{
	char	*var_name;
	int		j;

	j = 0;
	while (str[j] && str[j] != '=')
		j++;
	var_name = ft_strsub(str, 0, j + 1);
	return (var_name);
}

void	ft_error(char *err, int flag)
{
	ft_putendl_fd(err, 2);
	if (flag == 1)
		exit(1);
}
