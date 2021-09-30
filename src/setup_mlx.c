/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   setup_mlx.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mteerlin <mteerlin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/18 18:06:07 by mteerlin      #+#    #+#                 */
/*   Updated: 2021/09/30 13:29:06 by mteerlin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../hdr/fractol.h"
#include "../incl/libft/libft.h"
#include "../incl/mlx/mlx.h"

t_setfunc	setup_function(char *set)
{
	if (!ft_strncmp(set, "mandelbrot", 11))
		return (*mandelbrot);
	if (!ft_strncmp(set, "julia", 6))
		return (*julia);
	if (!ft_strncmp(set, "shipwreck", 7))
		return (*shipwreck);
	return (NULL);
}

t_data	setup_img_data(t_prog *prog)
{
	t_data	img;

	img.img = mlx_new_image(prog->mlx, prog->win.hori, prog->win.vert);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.line, &img.endian);
	return (img);
}

t_prog	setup_mlx(int x, int y, int argc, char **argv)
{
	t_prog	prog;

	prog.win.hori = x;
	prog.win.vert = y;
	prog.win.ar = (long double)x / (long double)y;
	prog.zoom = 1;
	prog.args = get_complex_comp(argc, argv);
	prog.setfunc = setup_function(argv[1]);
	prog.offset.real = 0;
	prog.offset.imag = 0;
	prog.iter = BASE_ITER;
	prog.mlx = mlx_init();
	prog.win.win = mlx_new_window(prog.mlx, x, y, argv[1]);
	prog.img[0] = setup_img_data(&prog);
	prog.img[1] = setup_img_data(&prog);
	return (prog);
}
