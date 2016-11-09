/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers_exec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fviolin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/28 16:23:06 by fviolin           #+#    #+#             */
/*   Updated: 2016/09/07 11:58:57 by adu-pelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <processes.h>

static char		**get_path_content(void)
{
	t_signal_var	*s;
	char			**paths;
	char			*var;

	s = singleton();
	var = get_node_content(s->env, "PATH=");
	paths = ft_strsplit(var, ':');
	free(var);
	return (paths);
}

char			*path_or_exec(t_parser *process)
{
	char	*cmd_path;
	char	*full_path;
	char	**paths;

	if (!ft_strncmp(process->content[0], "./", 2) &&
			!check_file_access(&process->content[0][2]))
		return (ft_strdup(&(process->content[0][2])));
	else if (!check_file_access(process->content[0]) &&
			!ft_strncmp(process->content[0], "/", 1))
		return (ft_strdup(process->content[0]));
	else
	{
		paths = get_path_content();
		cmd_path = get_cmd_path(process->content[0], paths);
		ft_freetab(paths);
		full_path = add_full_path(process->content, cmd_path);
		free(cmd_path);
		if (check_file_access(full_path) == 0 && ft_strchr(full_path, '/'))
			return (full_path);
		else
		{
			ft_strdel(&full_path);
			return (NULL);
		}
	}
}

void			close_fds(t_all *all)
{
	close(all->exec->stdin_cp);
	if (all->exec->fd_write > 2)
		close(all->exec->fd_write);
	all->exec->fd_write = 0;
	if (all->exec->fd_read > 2)
		close(all->exec->fd_read);
}
