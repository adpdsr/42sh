/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adu-pelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/26 18:34:47 by adu-pelo          #+#    #+#             */
/*   Updated: 2016/09/05 15:22:28 by adu-pelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH_H
# define SH_H

# include "../libft/libft.h"
# include <sys/types.h>
# include <sys/ioctl.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <sys/uio.h>
# include <termios.h>
# include <stdlib.h>
# include <unistd.h>
# include <dirent.h>
# include <stdio.h>
# include <fcntl.h>
# include <term.h>

# define MAGENTA "\033[35m"
# define YELLOW "\033[33m"
# define GREEN "\033[32m"
# define WHITE "\033[37m"
# define RESET "\033[00m"
# define BLACK "\033[30m"
# define BLUE "\033[34m"
# define CYAN "\033[36m"
# define RED "\033[31m"

# define HPATH ".history"
# define BUFFER *(unsigned int *)buffer

typedef struct winsize	t_winsize;
typedef struct termios	t_termios;

typedef struct		s_var
{
	int				exported;
	int				is_func;
	char			*name;
	char			*content;
	struct s_var	*next;
}					t_var;

typedef struct		s_pos
{
	int				x;
	int				y;
}					t_pos;

typedef struct		s_line
{
	int				prompt_len;
	int				paranthesis;
	int				dblquote;
	int				bquote;
	int				brace;
	int				quote;
	int				hook;
	int				href;
	int				flag;
	char			*cmd;
	char			*copy;
}					t_line;

typedef struct		s_term
{
	int				fd;
	t_termios		termios;
}					t_term;

typedef struct		s_env
{
	char			*name;
	char			*content;
	struct s_env	*next;
}					t_env;

typedef struct		s_exec
{
	pid_t			pid;
	int				fd[2];
	int				fd_write;
	int				fd_read;
	int				stdin_cp;
	int				stdout_cp;
}					t_exec;

typedef struct		s_all
{
	char			**paths;
	char			**env_tab;
	t_exec			*exec;
	t_env			*env;
	t_term			*term;
	t_var			*var;
}					t_all;

void				ft_error(char *err, int flag);
int					prompt(t_env *env);
t_term				*init_term();
void				exit_term();
int					ft_poutchar(int c);
char				*get_var_content(char *str);
char				*get_var_name(char *str);
char				**list_in_tab(t_env *list);
void				list_remove(t_env **node, char *var_name);
t_line				*init_line(t_line *line, int prompt_len);
t_all				*init_all(t_all *all, char **environ);
int					free_env_list(t_env **list);
void				sig_quit(int sig);
int					*pid(void);
void				set_signal();
void				restore_signal();
void				sig_clear(int sig);
char				**ft_strsplit_sh(char const *s, char c);
char				*clean_str(char *str, char *tmp);
char				*clean_backslah(char *str, char *tmp);

/*
** other/list.c
*/
char				*get_node_content(t_env *env, char *str);
void				set_node_content(t_env *env, char *index,\
	char *content);
void				env_push_back(t_env **head, t_env *new);
t_env				*env_create_node(char *environ);
void				list_remove(t_env **node, char *var_name);

/*
** free_prog.c
*/
void				free_env(t_env **env);
#endif
