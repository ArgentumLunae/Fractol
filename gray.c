/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   gray.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mteerlin <mteerlin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/07/21 12:25:03 by mteerlin      #+#    #+#                 */
/*   Updated: 2021/08/18 15:14:35 by mteerlin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/mlx/mlx.h"
#include "../incl/libft/libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include "../hdr/mandelbrot.h"
#define MAXITER 100

double zoomfactor = 1;

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

typedef struct s_complex
{
	double	real;
	double	imaginary;
}	t_complex;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->llength + x * (data->bpp / 8));
	*(unsigned int *)dst = color;
}

int	keypress(int keycode, t_vars *prog)
{
	static int	holdcounter;

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

int	buttonpress(int button, t_vars *prog)
{
	if (button == 4)
		zoomfactor *= 1.05;
	else if (button == 5)
		zoomfactor /= 1.05;
	else if (prog)
		printf("buttoncode: %i\n", button);
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

int	mandelbrot(double real, double complex)
{
	int			cnt;
	t_complex	z;
	double		realsq;
	double		complexsq;
	double		abs;

	z.real = 0;
	z.imaginary = 0;
	realsq = pow(real, 2);
	complexsq = pow(complex, 2);
	abs = sqrt(realsq + complexsq);
	cnt = 0;
	while (abs < 2 && cnt < MAXITER)
	{
		z.real = realsq - complexsq + real;
		z.imaginary = 2 * z.real * z.imaginary + complex;
		realsq = pow(z.real, 2);
		complexsq = pow(z.imaginary, 2);
		abs = sqrt(realsq + complexsq);
		cnt++;
	}
	return (cnt);
}

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

int	main(void)
{
	t_vars	prog;
	t_data	img;
	int		mandel;
	int		x;
	int		y;

	prog = setup_prog();
	img.img = mlx_new_image(prog.mlx, prog.hori, prog.vert);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.llength, &img.endian);
	y = 0;
	while (y < prog.vert)
	{
		x = 0;
		while (x < prog.hori)
		{
			mandel = mandelbrot((2.5 / zoomfactor) * (((double)x / (prog.hori / 2)) - 1), (2.5 / zoomfactor) * (((double)y / (prog.vert / 2)) - 1));
			if (mandel == MAXITER)
				my_mlx_pixel_put(&img, x, y, 0);
			else
				my_mlx_pixel_put(&img, x, y, (0xbfbfbf * mandel / MAXITER) + 0x404040);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(prog.mlx, prog.win, img.img, 0, 0);
	events(&prog);
	return (0);
}
