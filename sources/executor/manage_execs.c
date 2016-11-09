/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_execs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fviolin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/28 16:26:20 by fviolin           #+#    #+#             */
/*   Updated: 2016/09/07 11:59:59 by adu-pelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>
#include <builtins.h>
#include <processes.h>

static int	get_ret_value(t_all *all, t_parser *process)
{
	int		ret;
	char	*cmd_path;
	char	*full_path;

	cmd_path = get_cmd_path(process->content[0], all->paths);
	full_path = add_full_path(process->content, cmd_path);
	if (cmd_path)
		ft_strdel(&cmd_path);
	if ((ret = check_error_execute(all, process, full_path)))
	{
		ft_strdel(&full_path);
		return (ret);
	}
	if (full_path)
		ft_strdel(&full_path);
	return (0);
}

static int	exec_commands_fork(t_all *all, t_parser *process, char *path)
{
	int				status;
	t_signal_var	*s;

	s = singleton();
	all->exec->pid = fork();
	if (all->exec->pid == 0)
	{
		if ((execve(path, process->content, list_in_tab(s->env)) == -1))
			return (-1);
	}
	else if (all->exec->pid > 0)
	{
		waitpid(all->exec->pid, &status, 0);
		if ((dup2(all->exec->stdin_cp, 0)) == -1)
			return (-1);
		return (status);
	}
	return (-1);
}

int			exec_commands(t_all *all, t_parser *process)
{
	char			*full_path;
	int				builtin;
	int				status;
	t_signal_var	*s;

	s = singleton();
	builtin = while_builtins(s->input, &s->env, &all->var, process->content);
	if (builtin == -1)
	{
		if ((full_path = path_or_exec(process)) == NULL)
			return (get_ret_value(all, process));
		status = exec_commands_fork(all, process, full_path);
		free(full_path);
		return (check_status(status));
	}
	return (builtin);
}

int			exec_processes(t_all *all, t_parser *process)
{
	int				ret;
	char			*full_path;
	int				builtin;
	t_signal_var	*s;

	s = singleton();
	builtin = while_builtins(s->input, &s->env, &all->var, process->content);
	if (builtin == -1)
	{
		if ((full_path = path_or_exec(process)) == NULL)
		{
			if ((ret = check_error_execute(all, process, full_path)) != 0)
				exit(ret);
		}
		if ((execve(full_path, process->content, all->env_tab)) == -1)
			ft_error("42sh: exec error", 0);
		return (-1);
	}
	return (builtin);
}
