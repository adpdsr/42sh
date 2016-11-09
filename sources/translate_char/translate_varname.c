/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate_varname.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwells <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/03 11:32:48 by gwells            #+#    #+#             */
/*   Updated: 2016/09/08 19:10:52 by fviolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lineedit.h>
#include <builtins.h>

static char		*parse(t_env *env, char **splitted_cmd, char *actual)
{
	char	*tmp;
	char	*join;
	char	*parsed;
	char	*env_elem;
	char	*tmp2;

	join = NULL;
	parsed = NULL;
	tmp = return_min_str(splitted_cmd);
	parsed = ft_strsub(*splitted_cmd, 1, \
			(tmp) ? tmp - *splitted_cmd - 1 : (int)ft_strlen(*splitted_cmd));
	tmp2 = ft_strjoin(parsed, "=");
	free(parsed);
	env_elem = get_node_content(env, tmp2);
	free(tmp2);
	if (!env_elem)
	{
		*splitted_cmd = tmp;
		return (actual);
	}
	*splitted_cmd = tmp;
	join = ft_strjoin(actual, env_elem);
	free(env_elem);
	free(actual);
	return (join);
}

static char		*manage_dollar(char **str, char *res)
{
	char			*tmp2;
	char			*ret_val;
	t_signal_var	*s;

	s = singleton();
	if (*(*str + 1) == '?')
	{
		ret_val = do_retval(str);
		tmp2 = ft_strjoin(res, ret_val);
		free(res);
		free(ret_val);
		res = ft_strdup(tmp2);
		free(tmp2);
	}
	else
		res = parse(s->env, str, res);
	return (res);
}

char			*dollar_translate(t_inhib *line, char *str)
{
	int			dollar_count;
	char		*tmp;
	char		*res;

	dollar_count = 1;
	res = ft_strdup("");
	while (str && *str)
	{
		if (*str == '$' && if_dollar_translate(line, dollar_count))
		{
			res = manage_dollar(&str, res);
			dollar_count++;
		}
		else
		{
			if (*str == '$')
				dollar_count++;
			tmp = res;
			res = ft_append_char(res, *str);
			ft_strdel(&tmp);
			str++;
		}
	}
	return (res);
}
