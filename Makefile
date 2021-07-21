# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: mteerlin <mteerlin@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2021/07/21 12:25:06 by mteerlin      #+#    #+#                  #
#    Updated: 2021/07/21 14:11:54 by mteerlin      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME	= fractol

INCL_DIR = incl/
SRC_DIR = src/
SRC		= Gray.c

OBJ_DIR = obj/
OBJ		= $(OBJ_DIR)$(SRC:.c=.o)

LIBFT_DIR = $(INCL_DIR)libft/
LIBFT	= $(LIBFT_DIR)libft.a
MLX_DIR = $(INCL_DIR)mlx/
MLX		= $(MLX_DIR)libmlx.a

CFLAGS	= -Wall -Wextra -Werror -fsanitize=address -g

all: 		$(NAME)

$(NAME):	$(LIBFT) $(MLX) $(OBJ)
			$(CC) $(CFLAGS) -L$(MLX_DIR) -lmlx -L$(LIBFT_DIR) -lft -framework OpenGL -framework AppKit $(OBJ) -o $(NAME)

$(LIBFT):
			@$(MAKE) -C $(LIBFT_DIR) bonus

$(MLX):
			@$(MAKE) -C $(MLX_DIR)

$(OBJ_DIR)%.o:		$(SRC_DIR)%.c $(HDR)
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