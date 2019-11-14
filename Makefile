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
LBR_PATH := libft/

CC :=		gcc
CFLAGS :=	-g -Wall -Wextra -Werror
IFLAGS :=	-I $(INC_PATH)
LFLAGS :=


HFILES :=	mlx fdf

FILES :=  main \

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