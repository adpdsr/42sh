/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_func_tools.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwells <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/31 22:52:42 by gwells            #+#    #+#             */
/*   Updated: 2016/07/31 22:53:08 by gwells           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>
#include <builtins.h>

char		*func_name(char *cmd)
{
	int e;
	int s;
	int i;

	e = 0;
	s = 0;
	i = 0;
	while (ft_isspace(cmd[i]))
		i++;
	s = i;
	while (cmd[i] && !ft_isspace(cmd[i]) && cmd[i] != '(')
		i++;
	while (ft_isspace(cmd[i]))
		i++;
	if (cmd[i] == '(')
	{
		while (ft_isspace(cmd[i - 1]))
			i--;
		e = i;
	}
	return (ft_strsub(cmd, s, e - s));
}

char		*func_content(char *cmd)
{
	int e;
	int s;
	int i;

	e = 0;
	s = 0;
	i = 0;
	while (cmd[i] != '{')
		i++;
	while (ft_isspace(cmd[i + 1]))
		i++;
	s = i + 1;
	while (cmd[i] != '}')
		i++;
	while (ft_isspace(cmd[i - 1]))
		i--;
	e = i;
	return (ft_strsub(cmd, s, e - s));
}
