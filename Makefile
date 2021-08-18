# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: mteerlin <mteerlin@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2021/07/21 12:25:06 by mteerlin      #+#    #+#                  #
#    Updated: 2021/08/17 15:08:45 by mteerlin      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME	= fractol

INCL_DIR = incl/
SRC_DIR = src/
SRC		= zoom.c

OBJ_DIR = obj/
OBJ		= $(OBJ_DIR)$(SRC:.c=.o)

LIBFT_DIR = $(INCL_DIR)libft/
LIBFT	= $(LIBFT_DIR)libft.a
MLX_DIR = $(INCL_DIR)mlx/
MLXL_DIR = $(INCL_DIR)mlx_linux
MLX		= $(MLX_DIR)libmlx.a

CFLAGS	= -Wall -Wextra -Werror -fsanitize=address -g

all: 		$(NAME)

$(NAME):	$(LIBFT) $(MLX) $(OBJ)
#			$(CC) $(CFLAGS) -L$(MLX_DIR) -lmlx -L$(LIBFT_DIR) -lft -framework OpenGL -framework AppKit $(OBJ) -o $(NAME)
			$(CC) -fsanitize=address -g $(OBJ) -L$(MLXL_DIR) -lmlx -L$(LIBFT_DIR) -lft -Imlx -Ilibft -L/usr/lib -lXext -lX11 -lm -lz -o $(NAME)

$(LIBFT):
			$(MAKE) -C $(LIBFT_DIR) bonus

$(MLX):
#			$(MAKE) -C $(MLX_DIR)
			$(MAKE) -C $(MLXL_DIR)

$(OBJ_DIR)%.o:		$(SRC_DIR)%.c
			@mkdir -p $(dir $@)
			$(CC) $(CFLAGS) -c $< -o $@

clean:
			rm -f $(OBJ_DIR)*.o $(LIBFT_DIR)*.o $(MLX_DIR)*.o
			@rmdir -p $(OBJ_DIR)

fclean:
			$(MAKE) clean
			rm -f $(NAME) $(LIBFT) $(MLX)
re:
			$(MAKE) fclean
			$(MAKE) all