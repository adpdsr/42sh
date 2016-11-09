/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fviolin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/04 14:16:48 by fviolin           #+#    #+#             */
/*   Updated: 2016/09/08 15:06:16 by gwells           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>
#include <lineedit.h>
#include <processes.h>

void				insert_in_history(t_his **head, char *cmd)
{
	t_his	*tmp;
	char	*trim;

	tmp = *head;
	trim = ft_strtrim(cmd);
	recover_space(trim);
	*head = his_push_back(head, his_create_node(trim));
	ft_strdel(&trim);
	while (tmp)
	{
		if (tmp->select == 1)
		{
			if (tmp->next)
			{
				tmp->select = 0;
				tmp->next->select = 1;
			}
		}
		tmp = tmp->next;
	}
}

static void			get_first_line(t_event *event, t_all *all,
		t_signal_var *s, char **gnl)
{
	init_term();
	use_cap("ks");
	use_cap("im");
	set_signal();
	line_edition(event, all, 0);
	end();
	*gnl = ft_strdup(s->input->cmd_line);
	s->line = init_inhib_line(*gnl);
	active_quotes(s->line);
	active_bslash(s->line);
	ft_putchar('\n');
}

static void			launch_line_edit(t_event *event, t_all *all)
{
	t_signal_var	*s;
	char			*gnl;

	s = singleton();
	gnl = NULL;
	get_first_line(event, all, s, &gnl);
	while (check_inhib_bslash(s->input->cmd_line, 0) != 0
			|| check_inhib_bslash(s->input->cmd_line, 1) != 0
				|| check_inhib(s->line) != 0)
	{
		launch_sub_prompt(event, all, &gnl);
		ft_strdel(&gnl);
		gnl = save_str(s->line);
		ft_putchar('\n');
	}
	free(s->line);
	restore_signal();
	use_cap("ei");
	use_cap("ke");
	exit_term();
	free(s->input->cmd_line);
	s->input->cmd_line = gnl;
}

static void			prog_core(t_all *all)
{
	t_event			*event;
	t_signal_var	*s;

	s = singleton();
	init_var(&event);
	s->input->sprompt = prompt(s->env) + 4;
	while (42)
	{
		signal(SIGWINCH, sig_win_size);
		launch_line_edit(event, all);
		if (cmd_not_empty(s->input->cmd_line) && s->input->cmd_line\
		&& ft_strlen(s->input->cmd_line) > 0)
			multi_cmd(all, 0);
		free(s->input->cmd_line);
		s->input->cmd_line = ft_strdup("");
		s->input->sprompt = prompt(s->env) + 4;
	}
}

int					main(int ac, char **av, char **environ)
{
	t_all	*all;

	av = NULL;
	all = NULL;
	(void)av;
	if (ac != 1)
		ft_error("error: 21sh does not take any arguments", 1);
	all = init_all(all, environ);
	prog_core(all);
	return (0);
}
