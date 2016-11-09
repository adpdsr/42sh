/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwells <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/22 09:15:02 by gwells            #+#    #+#             */
/*   Updated: 2016/09/05 14:46:30 by gwells           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# define BUFF_SIZE 100

# include <string.h>
# include <stdint.h>
# include <wchar.h>

typedef struct		s_inhib
{
	char			c;
	int				active;
}					t_inhib;

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct		s_dnode
{
	void			*content;
	size_t			content_size;
	struct s_dnode	*next;
	struct s_dnode	*prev;
}					t_dnode;

typedef struct		s_dlist
{
	size_t			length;
	t_dnode			*head;
	t_dnode			*queue;
}					t_dlist;

typedef struct		s_pile
{
	void			*content;
	size_t			content_size;
	struct s_pile	*prev;
}					t_pile;

void				*ft_memalloc (size_t size);
void				ft_memdel (void **ap);
size_t				ft_strlen (const char *str);
char				*ft_strdup (const char *str);
char				*ft_strcpy (char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t n);
char				*ft_strcat (char *dst, const char *src);
char				*ft_strncat(char *dst, const char *src, size_t n);
char				*ft_strchr(const char *str, int c);
char				*ft_strrchr(const char *str, int c);
char				*ft_strstr(const char *str, const char *to_find);
char				*ft_strnstr(const char *str, const char *to_find, size_t n);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
void				*ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *str, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
int					ft_isdigit(int c);
int					ft_isspace(const char c);
int					ft_atoi(const char *str);
int					ft_isupper(int c);
int					ft_islower(int c);
int					ft_isalpha(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **app);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void(*f)(char*));
void				ft_striteri(char *s, void(*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char(*f)(char));
char				*ft_strmapi(char const *s, char(*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_putendl(char const *s);
void				ft_putnbr(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
char				*ft_itoa(int n);
char				**ft_strsplit(char const *s, char c);
void				*ft_memmove(void *dst, const void *src, size_t len);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *newnode);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
size_t				ft_list_size(t_list *begin_list);
t_list				*ft_lstdup(int size);
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void				ft_lstpushback(t_list **begin_list, t_list *lst);
char				*ft_union(char *argv);
t_dlist				*ft_dlstnew(void);
t_dnode				*ft_dlstnewnode(void const *content, size_t content_size);
t_dlist				*ft_dlstinsert(t_dlist *lst, t_dnode *newnode, size_t pos);
t_list				*ft_lstinsert(t_list *head, t_list *newnode, size_t pos);
void				ft_dlstadd(t_dlist *lst, t_dnode *newnode);
void				ft_dlstdel(t_dnode **alst, void (*del)(void *, size_t));
void				ft_dlstpushback(t_dlist *list, t_dnode *newnode);
void				ft_dlstdelone(t_dnode **alst, void (*del)(void *, size_t));
int					get_next_line(int const fd, char **line);
void				*ft_memalloc_fail(size_t size);
size_t				words(char const *str, char c);
int					ft_count_char(char *str, char c);
void				ft_putnchar(char c, int n);
void				ft_putnstr(char *str, int n);
void				ft_putnbrbase(uintmax_t nbr, char *base, size_t base_len);
int					ft_nbrlen_u(uintmax_t nbr);
size_t				ft_nbrlen(int nbr);
int					ft_nbrline(int fd);
void				ft_putnwstr(const wchar_t *str, size_t len);
void				ft_putwchar(wchar_t chr);
void				ft_putwchar_fd(wchar_t chr, int fd);
int					**ft_alloc_2d_int_tab(int x, int y);
void				ft_quit(const char *error, int fd, int code);
char				*ft_append_char(char *str, char c);
int					ft_open_file(char *str, int flag);
t_pile				*ft_pilenew(void const *content, size_t content_size);
void				ft_pilepush(t_pile **pile, t_pile *newnode);
t_pile				*ft_pilepop(t_pile **pile);
void				ft_pileswap(t_pile **pile);
void				ft_pilerotate(t_pile **pile);
void				ft_pilerrotate(t_pile **pile);
void				ft_qsort(void *ft_tab, size_t nb_elem, size_t size_elem,\
					int(*diff)(void *const a, void *const b));
void				ft_isort(void *ft_tab, size_t nb_elem, size_t size_elem,\
					int(*diff)(void const *a, void const *b));
size_t				ft_pilesize(t_pile *pile);
t_pile				*ft_piletail(t_pile *pile);
void				ft_dlistrrotate(t_dlist *list);
void				ft_dlistrotate(t_dlist *lst);
t_dnode				*ft_dlistpop(t_dlist *lst);
t_dnode				*ft_dlistrpop(t_dlist *lst);
void				ft_dlistswap(t_dlist *lst);
int					ft_abs(int i);
void				ft_strstriter(char **strstr, void (*f)(char *str));
char				*ft_strsupress_at(char *str, size_t pos);
char				*ft_strsupress_at(char *str, size_t pos);
char				*ft_strinsert_at(char *str, char c, size_t pos);
char				*ft_strpbrk(const char *s1, const char *s2);
char				*ft_strrpbrk(const char *s1, const char *s2);
int					ft_cntc(char *str, char c);
void				ft_freetab(char **tab);
char				**ft_strsplit_ws(char const *s1);
int					ft_tablen(char **tab);
void				ft_print_tab(char **tab);
int					ft_isstrdigit(char *s);
int					ft_isstralnum(char *s);
char				*ft_strpbrk2(const char *s1, const char *s2);
char				*ft_strtrimc(char const *s, char const c);
char				**ft_tabdup(char **tab);
void				ft_strsupress_at2(char **str, size_t pos);
int					ft_cntc_inhib(t_inhib *line, char *str, char c);
#endif
