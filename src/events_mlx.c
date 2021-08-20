/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   events_mlx.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mteerlin <mteerlin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/18 19:40:26 by mteerlin      #+#    #+#                 */
/*   Updated: 2021/08/19 13:10:10 by mteerlin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../hdr/fractol.h"
#include "../incl/mlx/mlx.h"
#include "stdlib.h"

int	close_prog(void)
{
	exit(EXIT_SUCCESS);
	return (0);
}

int	keypress_mlx(int keycode, t_prog *prog)
{
	if (keycode == 53)
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
		prog->zoom *= 1.05;
		gen_imgage(prog);
	}
	else if (button == 5 && y < prog->win.vert)
	{
		prog->zoom /= 1.05;
		gen_imgage(prog);
	}
	return (0);
}

void	events_mlx(t_prog *prog)
{
	mlx_hook(prog->win.win, 3, 1L << 1, keypress_mlx, prog);
	mlx_hook(prog->win.win, 4, 1L << 2, buttonpress_mlx, prog);
	mlx_hook(prog->win.win, 17, 0L, close_prog, prog);
	mlx_loop(prog->mlx);
}
