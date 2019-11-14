# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pmelodi <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/05 20:25:45 by pmelodi           #+#    #+#              #
#    Updated: 2019/09/15 17:16:12 by pmelodi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

OBJ_PATH :=	.obj/
SRC_PATH :=	srcs/
INC_PATH :=	includes/

CC :=		gcc
CFLAGS :=	-g -Wall -Wextra -Werror
IFLAGS :=	-I $(INC_PATH)

HFILES :=	libft get_next_line

FILES := ft_atoi ft_strcpy ft_strdup \
	   ft_isascii ft_strncpy ft_strcat \
	   ft_strstr ft_isprint ft_strlen \
	   ft_isalpha ft_isdigit ft_isalnum \
	   ft_toupper ft_tolower ft_strncat \
	   ft_strlcat ft_strchr ft_strrchr \
	   ft_memset ft_bzero ft_memcpy \
	   ft_memccpy ft_memmove ft_memchr \
	   ft_memcmp ft_strnstr ft_strcmp \
	   ft_strncmp \
	   ft_memalloc ft_memdel ft_strnew \
	   ft_strdel ft_strclr ft_striter \
	   ft_striteri ft_strmap ft_strmapi \
	   ft_strequ ft_strnequ ft_strsub\
	   ft_strjoin ft_strtrim ft_strsplit\
	   ft_putchar ft_putstr \
	   ft_iswhitespace ft_putnbr ft_putnbr_fd\
	   ft_putstr_fd ft_putchar_fd ft_putendl \
	   ft_putendl_fd ft_itoa \
	   ft_lstnew ft_lstdelone ft_lstdel \
	   ft_lstadd ft_lstiter ft_lstmap \
	   ft_numlen ft_iterative_power ft_cnt_words\
	   ft_lstlen ft_cntchr get_next_line\

HDRS =		$(addprefix $(INC_PATH), $(addsuffix .h, $(HFILES)))
SRC =		$(addprefix $(SRC_PATH), $(addsuffix .c, $(FILES)))
OBJS =		$(addprefix $(OBJ_PATH), $(addsuffix .o, $(FILES)))

all: $(NAME)

$(NAME): $(OBJ_PATH) $(OBJS)
	@ar rc libft.a $(OBJS)
	@ranlib libft.a

$(OBJ_PATH):
	@mkdir -p $(OBJ_PATH)
	@echo $(NAME): $(OBJ_PATH) was created

$(OBJ_PATH)%.o: $(SRC_PATH)%.c $(HDRS)
	@$(CC) $(CFLAGS) -c $(IFLAGS) $< -o $@

clean:
	@rm -rf $(OBJS)
	rm -rf $(OBJ_PATH)

fclean: clean
	@rm -rf libft.a

re: fclean all