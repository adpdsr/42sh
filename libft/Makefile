# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gwells <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/12/11 00:09:30 by gwells            #+#    #+#              #
#    Updated: 2016/09/05 14:45:01 by gwells           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a

SRC		=	ft_bzero.c \
			ft_isdigit.c \
			ft_memccpy.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_memset.c \
			ft_strcat.c \
			ft_strchr.c \
			ft_strcpy.c \
			ft_strdup.c \
			ft_strlen.c \
			ft_strncat.c \
			ft_strncpy.c \
			ft_strnstr.c \
			ft_strrchr.c \
			ft_strstr.c \
			ft_strcmp.c \
			ft_strncmp.c \
			ft_isspace.c \
			ft_isdigit.c \
			ft_atoi.c \
			ft_isupper.c \
			ft_islower.c \
			ft_isalpha.c \
			ft_isalnum.c \
			ft_isascii.c \
			ft_isprint.c \
			ft_toupper.c \
			ft_tolower.c \
			ft_memalloc.c \
			ft_memdel.c \
			ft_strnew.c \
			ft_strdel.c \
			ft_strclr.c \
			ft_striter.c \
			ft_striteri.c \
			ft_strmap.c \
			ft_strmapi.c \
			ft_strequ.c \
			ft_strnequ.c \
			ft_strsub.c \
			ft_strjoin.c \
			ft_strtrim.c \
			ft_putchar.c \
			ft_putstr.c \
			ft_putendl.c \
			ft_putnbr.c \
			ft_putchar_fd.c \
			ft_putstr_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c \
			ft_itoa.c \
			ft_strsplit.c \
			ft_memmove.c \
			ft_strlcat.c \
			ft_lstnew.c \
			ft_lstdelone.c \
			ft_lstdel.c \
			ft_lstadd.c \
			ft_lstiter.c \
			ft_list_size.c \
			ft_lstmap.c \
			ft_lstpushback.c \
			ft_union.c \
			ft_lstempty.c \
			ft_dlstnew.c \
			ft_dlstnewnode.c \
			ft_dlstinsert.c \
			ft_lstinsert.c \
			ft_dlstadd.c \
			ft_dlstpushback.c \
			ft_dlstdel.c \
			ft_dlstdelone.c \
			get_next_line.c \
			ft_memalloc_fail.c \
			words.c \
			ft_count_char.c \
			ft_putnstr.c \
			ft_putnchar.c \
			ft_putnbrbase.c \
			ft_nbrline.c \
			ft_nbrlen_u.c \
			ft_nbrlen.c \
			ft_putwstr.c \
			ft_putwchar.c \
			ft_putwchar_fd.c\
			ft_alloc_2d_int.c\
			ft_putwchar_fd.c \
			ft_quit.c \
			ft_append_char.c\
			ft_open_file.c\
			ft_pilenew.c\
			ft_pilepush.c\
			ft_pilepop.c\
			ft_pileswap.c\
			ft_pilerotate.c\
			ft_pilerrotate.c\
			ft_memcpy.c\
			ft_qsort.c\
			ft_isort.c\
			ft_pilesize.c\
			ft_piletail.c\
			ft_dlistpop.c\
			ft_dlistrotate.c\
			ft_dlistrrotate.c\
			ft_dlistrpop.c\
			ft_dlistswap.c\
			ft_abs.c\
			ft_strstriter.c\
			ft_strsupress_at.c\
			ft_strinsert_at.c\
			ft_strpbrk.c\
			ft_strrpbrk.c\
			ft_cntc.c\
			ft_freetab.c\
			ft_strsplit_ws.c\
			ft_tablen.c \
			ft_print_tab.c \
			ft_isstrdigit.c \
			ft_isstralnum.c\
			ft_strpbrk2.c\
			ft_strtrimc.c\
			ft_tabdup.c\
			ft_cntc_inhib.c

OBJ		= $(SRC:.c=.o)

CC		= gcc -g
CFLAGS	= -Wall -Wextra -Werror

# **************************************************************************** #
$(NAME): $(OBJ)
	ar -rc $(NAME) $(OBJ) && ranlib $(NAME)

all: $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME) a.out

re: fclean $(NAME)
