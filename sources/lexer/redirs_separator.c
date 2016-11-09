/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirs_separator.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adu-pelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/24 20:22:33 by adu-pelo          #+#    #+#             */
/*   Updated: 2016/09/07 12:30:54 by fviolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>
#include <processes.h>

int		is_agreg_redir(char *str, int i)
{
	int start;
	int	len;

	start = i;
	len = 0;
	while (ft_isdigit(str[i]))
		i++;
	if (str[i] == '>')
		len = is_agreg_greater(str, i, start);
	if (str[i] == '<')
		len = is_agreg_lesser(str, i, start);
	return (len);
}

int		is_agreg_greater(char *str, int i, int start)
{
	i++;
	if (str[i] == '>')
	{
		i++;
		return (i - start);
	}
	else if (str[i] == '&')
	{
		i++;
		if (str[i] == '-')
			return (i - start + 1);
		else if (ft_isdigit(str[i]))
		{
			while (ft_isdigit(str[i]))
				i++;
			return (i - start);
		}
		else
			ft_putendl_fd("42sh: parse error near '\\n'", 2);
		return (-1);
	}
	else
		return (i - start);
}

int		is_agreg_lesser(char *str, int i, int start)
{
	i++;
	if (str[i] == '<')
	{
		i++;
		return (i - start);
	}
	else if (str[i] == '&')
	{
		i++;
		if (str[i] == '-')
			return (i - start + 1);
		else if (ft_isdigit(str[i]))
		{
			while (ft_isdigit(str[i]))
				i++;
			return (i - start);
		}
		else
			ft_putendl_fd("42sh: parse error near '\\n'", 2);
		return (-1);
	}
	else
		return (i - start);
}

int		is_greater_redir(char *str, int i)
{
	int start;

	start = i;
	if (str[i + 1])
	{
		i += 1;
		if (str[i] == '>')
			return (i - start + 1);
		else if (str[i] == '&')
		{
			i++;
			if (str[i] == '-')
				return (i - start + 1);
			else if (ft_isdigit(str[i]))
			{
				while (ft_isdigit(str[i]))
					i++;
				return (i - start);
			}
			else
				ft_putendl_fd("42sh: parse error near '\\n'", 2);
			return (-1);
		}
	}
	return (1);
}

int		is_lesser_redir(char *str, int i)
{
	int start;

	start = i;
	if (str[i + 1])
	{
		i += 1;
		if (str[i] == '<')
			return (i - start + 1);
		else if (str[i] == '&')
		{
			i++;
			if (str[i] == '-')
				return (i - start + 1);
			else if (ft_isdigit(str[i]))
			{
				while (ft_isdigit(str[i]))
					i++;
				return (i - start);
			}
			else
				ft_putendl_fd("42sh: parse error near '\\n'", 2);
			return (-1);
		}
	}
	return (1);
}
