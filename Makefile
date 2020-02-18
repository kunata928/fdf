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

NAME = fdf

GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

SRC_PATH :=		srcs/
INC_PATH :=		includes/
LIB_PATH :=		libft/
MLX_PATH :=		minilibx/
OBJ_PATH :=		.obj/

CC :=		gcc
CFLAGS :=	-g -Wall -Wextra -Werror
IFLAGS :=	-I $(INC_PATH) -I $(LIB_PATH)
LFLAGS :=   -lft -L $(LIB_PATH)
MLXFLAGS :=	-lmlx -framework OpenGL -framework AppKit

HFILES :=	fdf

FILES :=  main fdf_read fdf_error fdf_atoi fdf_plot \
        fdf_plot_line matrix_operations \
        fdf_keyboard fdf_rotate fdf_init \
        fdf_center fdf_color fdf_shift_zoom \
        fdf_color_gradient fdf_menu fdf_open_close \
        fdf_isometry help_func\

LIB :=		$(LIB_PATH)libft.a
MLX :=		$(MLX_PATH)libmlx.a

HDRS =		$(addprefix $(INC_PATH), $(addsuffix .h, $(HFILES)))
SRCS =		$(addprefix $(SRC_PATH), $(addsuffix .c, $(FILES)))
OBJS =		$(addprefix $(OBJ_PATH), $(SRCS:%.c=%.o))

all: $(NAME)

$(NAME): $(LIB) $(OBJ_PATH) $(OBJS) $(MLX)
	@ $(CC) $(CFLAGS) $(IFLAGS) $(LFLAGS) $(OBJS) -o $(NAME) $(MLX) $(MLXFLAGS)
	@echo "\n$(GREEN)Fdf created$(RESET)"

$(LIB):
	@ $(MAKE) -C $(dir $@) $(notdir $@)

$(OBJ_PATH):
	@ mkdir -p $(OBJ_PATH)$(SRC_PATH)
$(OBJ_PATH)%.o: %.c $(HDRS)
	@ $(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@
	@echo -n '.'

clean:
	@ rm -f $(OBJS)
	@ make clean -C $(LIB_PATH)
	@echo "$(RED)Objs deleted$(RESET)"

fclean: clean
	@ rm -f $(NAME)
	@ rm -rf $(OBJ_PATH)
	@ make fclean -C $(LIB_PATH)
	@echo "$(RED)Fdf deleted$(RESET)"

re: fclean all

norm:
	@norminette srcs/
	@norminette includes/fdf.h
	@norminette libft/srcs/
	@norminette libft/includes/