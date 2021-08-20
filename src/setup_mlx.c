/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   setup_mlx.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mteerlin <mteerlin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/18 18:06:07 by mteerlin      #+#    #+#                 */
/*   Updated: 2021/08/20 12:04:16 by mteerlin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../hdr/fractol.h"
#include "../incl/mlx/mlx.h"

t_prog	setup_mlx(int x, int y, char **argv)
{
	t_prog	prog;

	prog.win.hori = x;
	prog.win.vert = y;
	prog.zoom = 1;
	prog.argv = argv;
	prog.mlx = mlx_init();
	prog.win.win = mlx_new_window(prog.mlx, x, y, argv[1]);
	return (prog);
}

t_data	setup_img_data(t_prog *prog)
{
	t_data	img;

	img.img = mlx_new_image(prog->mlx, prog->win.hori, prog->win.vert);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.llength, &img.endian);
	return (img);
}
