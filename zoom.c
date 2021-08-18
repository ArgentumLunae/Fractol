/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   zoom.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mteerlin <mteerlin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/17 14:20:09 by mteerlin      #+#    #+#                 */
/*   Updated: 2021/08/18 14:31:20 by mteerlin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/mlx/mlx.h"
#include "../incl/libft/libft.h"
#include <stdbool.h>
#include <math.h>
#include <limits.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

double	g_zoom;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bpp;
	int		llength;
	int		endian;
}	t_data;

typedef struct s_vars
{
	bool	holdkey;
	void	*mlx;
	void	*win;
	int		hori;
	int		vert;
}	t_vars;

t_vars	setup_prog(void)
{
	t_vars prog;

	prog.hori = 500;
	prog.vert = 500;
	prog.holdkey = false;
	prog.mlx = mlx_init();
	prog.win = mlx_new_window(prog.mlx, prog.hori, prog.vert, "zoom");
	return (prog);
}

t_data	setup_data(t_vars *prog)
{
	t_data	img;

	img.img = mlx_new_image(prog->mlx, prog->hori, prog->vert);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.llength, &img.endian);
	return (img);
}

int	rainbow_circle(float x, float y)
{
	float	modulus;
	int		colour;

	modulus = sqrt(pow(x, 2) + pow(y, 2));
	if ((int)modulus == 0)
		colour = (0xffffff);
	else
		colour = 0xffffff - (int)modulus;
	return (colour);
}

void	create_img(t_vars *prog)
{
	int	x;
	int	y;
	int	colour;

	y = 0;
	ft_putnbr_fd(prog->hori, 1);
	while (y < prog->hori)
	{
		x = 0;
		while (x < prog->vert)
		{
			colour = rainbow_circle((x - prog->hori / 2) / g_zoom, (y - prog->vert / 2) / g_zoom);
			mlx_pixel_put(prog->mlx, prog->win, x, y, colour);
			x++;
		}
		y++;
	}
}

int	keypress(int keycode, t_vars *prog)
{
	static int	holdcounter;

	printf("access program: %d\n", prog->hori);
	if (prog->holdkey == false)
	{
		prog->holdkey = true;
		printf("keycode: %i\n", keycode);
		holdcounter = 0;
	}
	else
		holdcounter++;
	if (holdcounter == 25)
		printf("would you like to activate sticky keys\n");
	return (0);
}

int	keyrelease(int keycode, t_vars *prog)
{
	if (keycode == 53)
	{
		mlx_destroy_window(prog->mlx, prog->win);
		exit(EXIT_SUCCESS);
	}
	prog->holdkey = false;
	return (0);
}

int	buttonpress(int button, int x, int y, t_vars *prog)
{
	printf("cursor coordinates, [%d, %d]\n", x, y);
	if (button == 4)
	{
		g_zoom *= 1.05;
		create_img(prog);
	}
	else if (button == 5)
	{
		g_zoom /= 1.05;
		create_img(prog);
	}
	return (button);
}

int	enterwin(void)
{
	printf("Hello!\n");
	return (0);
}

int	exitwin(void)
{
	printf("Good bye\n");
	return (0);
}

int closeprog(void)
{
	exit(EXIT_SUCCESS);
	return (0);
}

int	events(t_vars *prog)
{
	mlx_hook(prog->win, 2, 1L << 0, keypress, prog);
	mlx_hook(prog->win, 3, 1L << 1, keyrelease, prog);
	mlx_hook(prog->win, 4, 1L << 2, buttonpress, prog);
	mlx_hook(prog->win, 7, 1L << 4, enterwin, prog);
	mlx_hook(prog->win, 8, 1L << 5, exitwin, prog);
	mlx_hook(prog->win, 17, 0L, closeprog, prog);
	mlx_loop(prog->mlx);
	return (0);
}

int	main(void)
{
	t_vars	prog;

	prog = setup_prog();
	g_zoom = 1;
	create_img(&prog);
	events(&prog);
	return (0);
}
