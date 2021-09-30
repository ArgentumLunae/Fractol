# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: mteerlin <mteerlin@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2021/07/21 12:25:06 by mteerlin      #+#    #+#                  #
#    Updated: 2021/09/30 13:53:49 by mteerlin      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

include sources.mk

NAME	= fractol

INCL_DIR := incl/
HDR_DIR := hdr/
HDR		:= fractol.h
SRCSFL	:= sources.txt
SRC_DIR := src/

OBJ_DIR := obj/
OBJ		:= $(addprefix $(OBJ_DIR), $(SRC:.c=.o))

LIBFT_DIR := $(INCL_DIR)libft/
LIBFT	:= $(LIBFT_DIR)libft.a
ifeq ($(shell uname), Darwin)
 MLX_DIR := $(INCL_DIR)mlx/
else
 MLXL_DIR := $(INCL_DIR)mlx_linux
endif
MLX		:= $(MLX_DIR)libmlx.a

CFLAGS	?= -Wall -Wextra -Werror

all: 		$(NAME)

$(NAME):	$(LIBFT) $(MLX) $(OBJ)
			$(CC) $(CFLAGS) -fsanitize=address -g -L$(MLX_DIR) -lmlx -L$(LIBFT_DIR) -lft -framework OpenGL -framework AppKit $(OBJ) -o $(NAME)
#			$(CC) $(OBJ) -L$(MLX_DIR) -lmlx -L$(LIBFT_DIR) -lft -Imlx -Ilibft -L/usr/lib -lXext -lX11 -lm -lz -o $(NAME)

$(LIBFT):
			$(MAKE) -C $(LIBFT_DIR) bonus

$(MLX):
			$(MAKE) -C $(MLX_DIR)

$(OBJ_DIR)%.o:		$(SRC_DIR)%.c $(HDR_DIR)$(HDR)
			@mkdir -p $(dir $@)
			$(CC) $(CFLAGS) -c $< -o $@

clean:
			rm -f $(OBJ_DIR)*.o
			@rmdir -p $(OBJ_DIR)

fclean:
			$(MAKE) clean
			rm -f $(NAME) $(LIBFT_DIR)*.o $(LIBFT) $(MLX) $(MLX_DIR)*.o
re:
			$(MAKE) fclean
			$(MAKE) all