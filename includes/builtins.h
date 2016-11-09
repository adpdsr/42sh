/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwells <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/24 13:43:14 by gwells            #+#    #+#             */
/*   Updated: 2016/09/07 12:16:55 by fviolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include <sh.h>
# include <lineedit.h>

# define BUILTINS 9
# define CD 0
# define ENV 1
# define SETEV 2
# define USETEV 3
# define BECHO 4
# define HISTORY 5
# define EXPORT 6
# define UNSET 7
# define EXIT 8
# define PATH_MAX_SIZE 1024

typedef int		(*t_func)(t_input *input, t_env **env, t_var **var, char **cmd);
typedef int		(*t_func_cd)(char **cmd, t_env *env);

int				while_builtins(t_input *input, t_env **env,
		t_var **var, char **cmd);
int				do_unsetenv(t_input *input, t_env **env,
		t_var **var, char **cmd);
int				do_history(t_input *input, t_env **env,
		t_var **var, char **cmd);
int				do_setenv(t_input *input, t_env **env,
		t_var **var, char **cmd);
int				do_export(t_input *input, t_env **env,
		t_var **var, char **cmd);
int				do_exit(t_input *input, t_env **env,
		t_var **var, char **cmd);
int				do_echo(t_input *input, t_env **env,
		t_var **var, char **cmd);
int				do_unset(t_input *input, t_env **env,
		t_var **var, char **cmd);
int				do_env(t_input *input, t_env **env,
		t_var **var, char **cmd);
int				do_cd(t_input *input, t_env **env,
		t_var **var, char **cmd);
int				check_file_access(char *path);
int				check_status(int status);
int				is_builtin(char *cmd);
void			replace(int coor, char **env, char *elem);
char			*tab_to_str(char **cmd);

int				error_env(int err);
int				error_unset(int err);
int				error_setenv(int err);
int				error_export(int err);
int				error_history(int err);

void			fill_var(t_var **head, char *cmd, int exp, int is_f);

/*
** history_tools.c
*/
int				get_histsize(t_env *env);
int				get_filelen(char *histpath);
int				get_nbcopy(t_his *his, int hfilelen);
int				history_len(t_his **head);
int				delete_history(t_his **head);
void			h_insert(void);

/*
** init.c
*/
t_env			*fill_env(t_env **env, t_env **cp, char **environ, int i);
t_env			*env_create_node(char *environ);
void			env_push_back(t_env **head, t_env *new);

/*
** builtin_print.c
*/
int				print_echo(char *cmd, int j);
void			print_history(t_his **head, int len);
void			print_vars(t_var *head, int only_exported);

/*
** free_prog.c
*/
void			free_prog(t_var **var, t_env **env);

/*
** shell_func.c
*/
int				is_shell_func(char **cmd, int i, int j);
char			*func_name(char *cmd);
char			*func_content(char *cmd);
void			fill_var(t_var **head, char *cmd, int exp, int is_f);

/*
** var_list.c
*/
void			var_push_back(t_var **head, t_var *new);
t_var			*var_new_node(char *cmd, int exp, int is_f);
int				check_shell_var(t_var **var, char **cmd);

/*
** env_tools.c
*/
void			print_env(t_env *env);
int				try_fork_bin(t_env *new, char **cmd, int i);
t_env			*list_cpy(t_env **head, t_env *new, t_env *elem,
		t_env *prev_elem);

/*
** echo_tools.c
*/
char			*get_dollar(char *str, t_env *head);

/*
** export_tools.c
*/
char			**read_export_args_norme(char **res, char *cmd, t_var **v);

/*
** unset_tools.c
*/
void			delete_var_node(t_var **head, t_var *cur,\
	char *to_del, int *opt);

/*
** shell_func_tools.c
*/
char			*func_name(char *cmd);
char			*func_content(char *cmd);

/*
** do_cd.c
*/
char			*resolve_dir(char *cmd, t_env *env, int opt);
int				change_directory(t_env *env, char *path, int opt);

/*
** cd/cannonical.c
*/
char			*posix_step_a_dot(char *path);
char			*posix_step_a_slash(char *path);
char			*apply_posix_dotdot(char *path);
char			*del_last_slash(char *path);
char			*del_last_point(char *path);

/*
** cd/relative_path.c
*/
char			*pwd_handle(t_env *env, char *cmd, int opt);
char			*cd_path_handle(t_env *env, char *cmd, int i);

/*
** cd/cd_utils.c
*/
char			*path_join(char *base, char *cmd);
int				is_dir(char *path);
int				if_absolute(char *cmd);
int				error(char *path);

/*
** cd/home.c
*/
char			*resolve_home(char *cmd, t_env *env);

/*
** cd/ptrfunc_cd.c
*/
int				cmd_handle(char **cmd, t_env *env);
char			*do_retval(char **str);
#endif
