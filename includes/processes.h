/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processes.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adu-pelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/24 20:17:08 by adu-pelo          #+#    #+#             */
/*   Updated: 2016/09/07 19:14:56 by fviolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROCESSES_H
# define PROCESSES_H

# include <libft.h>
# include <sh.h>
# include "lineedit.h"

typedef	enum		e_token_id
{
	PIPE,
	LESS,
	GREAT,
	DGREAT,
	DLESS,
	OR,
	AND,
	QUOTE,
	DQUOTE,
	CMD,
	BQUOTE,
	DOLLAR,
	END_LIST,
	ERROR
}					t_token_id;

typedef struct		s_lexer
{
	int				token;
	char			*content;
	char			**cmd;
	struct s_lexer	*next;
	struct s_lexer	*prev;
}					t_lexer;

typedef struct		s_parser
{
	int				r_stdin;
	int				r_stdout;
	int				r_shutout_out;
	int				r_shutout_in;
	int				token;
	char			**content;
	struct s_parser	*next;
}					t_parser;

/*
** lexer
*/
t_lexer				*fill_lexer(t_lexer *list, char *str, int flag);
int					is_separator(char c);
int					is_and(char *str, int i);
int					is_pipe(char *str, int i);
int					is_quote(char *str, int i);
int					is_bquote(char *str, int i);
int					is_dquote(char *str, int i);
int					is_agreg_redir(char *str, int i);
int					is_greater_redir(char *str, int i);
int					is_lesser_redir(char *str, int i);
int					is_agreg_lesser(char *str, int i, int start);
int					is_agreg_greater(char *str, int i, int start);
int					is_active_token(t_inhib *line, int start, int len);
void				free_lexer_list(t_lexer **head);

/*
** parser
*/
t_parser			*fill_parser(t_parser *list, t_lexer *list_lex, int token);
t_parser			*do_parsing(t_all *all, t_lexer *list_lex,
						t_parser *processes);
void				free_parser_list(t_parser **head);
void				tool_print_parser_list(t_parser *process);
int					error_handling_parser(t_all *all, t_parser *process);
int					update_fds_output(t_all *all, t_parser *processes);
void				do_redir_output(t_all *all, t_parser *processes);
int					do_redir_input(t_all *all, t_parser *processes);
int					count_fd_digit_len(char *str, int i);
void				open_file_for_redir(t_all *all, t_lexer *lex);
int					manage_io_files(t_all *all, t_lexer *list,
						t_parser *processes, int token);

/*
** pipes
*/
int					redir_to_pipes(t_all *all, t_parser *processes);
int					do_pipes(t_all *all, t_parser *processes);

/*
** redirections
*/
int					do_heredoc(t_all *all, t_parser *processes);
void				heredoc_process(t_parser *processes, t_all *all);
t_parser			*manage_redirs_processes(t_all *all, t_parser *processes);

/*
** exec
*/
int					exec_commands(t_all *all, t_parser *process);
char				*path_or_exec(t_parser *processes);
int					check_error_execute(t_all *all, t_parser *processes,
						char *path);
t_parser			*manage_logical_operators(t_all *all, t_parser *process,
						int flag);
void				close_fds(t_all *all);
int					check_file_access(char *path);
char				*get_cmd_path(char *cmd, char **paths);
char				*add_full_path(char **cmd, char *path);
void				exec_redir_processes(t_all *all, t_parser *list);
int					execute_manager(t_all *all, t_parser *process);
int					exec_processes(t_all *all, t_parser *list);
void				multi_cmd(t_all *all, int i);

#endif
