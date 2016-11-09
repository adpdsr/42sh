/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lineedit.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adu-pelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 16:10:32 by gwells            #+#    #+#             */
/*   Updated: 2016/09/08 20:45:38 by adu-pelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINEEDIT_H
# define LINEEDIT_H

# include "libft.h"
# include "sh.h"

# include <termios.h>
# include <term.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/ioctl.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <unistd.h>
# include <signal.h>

# define WHILE1 14
# define UP 0
# define DOWN 1
# define LEFT 2
# define RIGHT 3
# define DEL 4
# define HOME 5
# define END 6
# define FWORD 7
# define BWORD 8
# define CP 9
# define SUP 10
# define PAST 11
# define HISTORY_UP 12
# define HISTORY_DOWN 13

# define T_UP 0x415B1B1B
# define T_DOWN 0x425B1B1B
# define T_LEFT 0x444F1B
# define T_RIGHT 0x434F1B
# define T_DEL 0x7F
# define T_HOME 0x01
# define T_END 0x05
# define T_FWORD 0x92C6
# define T_BWORD 0xAB88E2
# define T_VISUAL 0x9FC3
# define T_CUT 0x8889E2
# define T_CP 0xA7C3
# define T_SUP 0x4
# define T_PAST 0x9A88E2
# define T_ENTER 0xA
# define T_HUP 0x414F1B
# define T_HDOWN 0x424F1B
# define T_QUIT 0x4
# define T_CLEAR 0x2
# define WHILE2 2
# define CLEFT 0
# define CRIGHT 1

# define INIBH 5
# define BRACE 0
# define PARENTHESIS 1
# define FTDQUOTE 2
# define SQUOTE 3
# define BSLASH 4

typedef struct		s_cursor
{
	int				x;
	int				y;
}					t_cursor;

typedef struct		s_his
{
	int				end;
	int				listed;
	int				select;
	char			*cmd;
	struct s_his	*next;
	struct s_his	*prev;
}					t_his;

typedef struct		s_input
{
	t_cursor		*cursor;
	int				sprompt;
	char			*cmd_line;
	char			*cp;
	t_his			*history;
	int				is_h;
}					t_input;

typedef struct		s_event
{
	void			(*w1ptrfunc[WHILE1])(struct s_event *event);
	void			(*w2ptrfunc[WHILE2])(struct s_event *event);
	void			*buffer;
	int				*move;
	int				*cmove;
}					t_event;

typedef struct		s_signal_var
{
	t_input			*input;
	t_term			*term;
	t_env			*env;
	int				ret;
	int				pid;
	int				fd;
	char			*abs_path;
	t_inhib			*line;
	t_winsize		ws;
}					t_signal_var;

typedef	void		(*t_funcwhile1)(t_event *event);
typedef	void		(*t_funcwhile2)(t_event *event);
/*
** main.c
*/
void				insert_in_history(t_his **head, char *cmd);

/*
** insert.c
*/
char				*insert_at(char *buffer, char c);
void				insert_rec(int y, char *buffer, int rec);

/*
** ptrfunc.c
*/
void				setup_while1(t_funcwhile1 *ptrfunc);
void				setup_while2(t_funcwhile2 *ptrfunc);

/*
** del.c
*/
void				del_at();
void				del();

/*
** line_edit_tools.c
*/
void				use_cap(char *cap);
char				*fetch_cap(char *cap);
void				putchar_move_cursor();
void				use_ncap(char *cap, int n);
int					check_max(t_cursor *cursor, char *cmd_line, int index);

/*
** ioctl.c
*/
int					fd_ioctl();

/*
** winsize.c
*/
void				get_winsize();
int					cursor_to_sbuffer(int x, int y);
int					line_full(int len, int y, int sprompt);
void				buffer_to_cursor(int pos, t_cursor *cursor);

/*
** init.c
*/
int					*init_move_tab();
int					*init_cmove_tab();
void				init_var(t_event **even);

/*
** move.c
*/
void				move_left();
void				move_right();
void				move_down();
void				move_up();
void				setup_while1(t_funcwhile1 *ptrfunc);

/*
** line_edition.c
*/
void				line_edition(t_event *event, t_all *all, int sub);

/*
** line_edition2.c
*/
char				*line_edit1(int sub, char *buffer);

/*
** select.c
*/
void				select_c(t_event *event);

/*
** move_select.c
*/
void				smove_left();
void				smove_right();

/*
** home_end.c
*/
void				home();
void				end();

/*
** fword_bword
*/
void				fword();
void				bword();

/*
** cut.c
*/
void				cut(t_event *event, t_cursor cur);

/*
** utils.c
*/
void				supress_end();
void				split_cmd_line(int pos_cu, int pos);

/*
** copy.c
*/
void				copy(t_event *event, t_cursor cur);

/*
** past.c
*/
void				past();

/*
** history.c
*/
t_his				*his_create_node(char *cmd);
t_his				*create_history(t_his *his, t_env *env);
t_his				*his_push_back(t_his **head, t_his *new);
void				append_history(t_his *his, t_env *env);

char				*get_history_line(t_his **head, char *cmd);
void				select_history_up(t_his *his);
void				select_history_down(t_his *his);
void				set_selection(t_his *tmp);
void				set_history(t_his *his, char *cmd);

/*
** history2.c
*/
void				supress_line();
void				history_up();
void				history_down();
void				print_line();

/*
** read_inhib.c
*/
int					read_inhib(t_inhib *line, int *i, char c);

/*
** check_line.c
*/
int					check_if_print(char *s, int index, int start, int end);
int					check_exclamation(char *s, int index);
int					cmd_not_empty(char *s);

/*
** check_inhib.c
*/
int					check_inhib_bslash(char *tmp, int mode);
int					check_inhib(t_inhib *line);

/*
** gnl.c
*/
t_inhib				*newline_append(char *str);
t_inhib				*newline_append2(char *str);
void				gnl(char *str, char *null);
void				active_quotes(t_inhib *line);
char				*save_str(t_inhib *line);

/*
** hack_space.c
*/
void				recover_space(char *line);
void				supress_bslash_space(t_inhib *line);

/*
** inhib_tools.c
*/
int					line_len(t_inhib *line, int mode);
void				print_inhib_line(t_inhib *line);
char				*inhib_to_input_cmd_line(t_inhib *line);
t_inhib				*init_inhib_line(char *str);

/*
** signal.c
*/
void				sig_win_size();
t_signal_var		*singleton();
void				sig_term(int sig);

/*
** free_line.c
*/
void				free_singleton();

/*
** history_tools2.c
*/
char				**tab_from_file(t_his *his, char *histpath, int nb_del);

/*
** get_last_history_match.c
*/
char				*translate_excla(char *splitted_cmd, char *res, char *tmp);

/*
** bang.c
*/
char				*choose_option(char *parsed);
char				*to_search(char *rest);

/*
** eol_bslash.c
*/
void				active_bslash(t_inhib *line);

/*
**pimp_my_strsplit.c
*/
char				**ft_strsplit_inhib(void);
int					check_semicolon(t_inhib *line);
int					count_semicolon_active(t_inhib *line);

/*
** quotes.c
*/
int					bslash_before(t_inhib *line, int index);

/*
** translate_varname.c
*/
char				*dollar_translate(t_inhib *line, char *str);
int					if_dollar_translate(t_inhib *line, int count);
char				*return_min_value(char *str1, char *str2);
char				*return_min_str(char **splitted_cmd);

/*
** sub_shell.c
*/
void				launch_sub_prompt(t_event *event, t_all *all, char **gnl);

#endif
