/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   events_mlx.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mteerlin <mteerlin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/18 19:40:26 by mteerlin      #+#    #+#                 */
/*   Updated: 2021/08/26 17:43:05 by mteerlin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../hdr/fractol.h"
#include "../hdr/keycodes.h"
#include "../incl/mlx/mlx.h"
#include "stdlib.h"
#include <stdio.h>

int	close_prog(void)
{
	exit(EXIT_SUCCESS);
	return (0);
}

int	keypress_mlx(int keycode, t_prog *prog)
{
	if (keycode == K_LEFT || keycode == K_RIGHT \
	    || keycode == K_UP || keycode == K_DOWN)
		translate(keycode, prog);
	if (keycode == K_NUMTWO || keycode == K_NUMFOUR \
		|| keycode == K_NUMSIX || keycode == K_NUMEIGHT)
		alter_fractal(keycode, prog);
	if (keycode == K_ZERO && prog->keyheld == K_LCTRL)
		reset_transform(prog);
	prog->keyheld = keycode;
	return (0);
}

int	keyrelease_mlx(int keycode, t_prog *prog)
{
	if (keycode == prog->keyheld)
		prog->keyheld = 0;
	if (keycode == K_ESC)
	{
		mlx_destroy_window(prog->mlx, prog->win.win);
		close_prog();
	}
	return (0);
}

int	buttonpress_mlx(int button, int x, int y, t_prog *prog)
{
	if (button == 4 && x < prog->win.hori)
	{
		get_translation(prog, x, y);
		prog->zoom *= ZOOM_FACT;
		increment_iterations(prog);
		gen_imgage(prog);
	}
	else if (button == 5 && y < prog->win.vert)
	{
		prog->zoom /= ZOOM_FACT;
		gen_imgage(prog);
	}
	return (0);
}

void	events_mlx(t_prog *prog)
{
	mlx_hook(prog->win.win, 2, 1L << 0, keypress_mlx, prog);
	mlx_hook(prog->win.win, 3, 1L << 1, keyrelease_mlx, prog);
	mlx_hook(prog->win.win, 4, 1L << 2, buttonpress_mlx, prog);
	mlx_hook(prog->win.win, 17, 0L, close_prog, prog);
	mlx_loop(prog->mlx);
}
