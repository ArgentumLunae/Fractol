/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   setup_img.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mteerlin <mteerlin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/18 20:02:37 by mteerlin      #+#    #+#                 */
/*   Updated: 2021/08/20 12:00:44 by mteerlin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../hdr/fractol.h"
#include "../incl/mlx/mlx.h"
#include <stdlib.h>

t_data	setup_img(t_prog *prog)
{
	t_data	img;

	img.img = mlx_new_image(prog->mlx, prog->win.hori, prog->win.vert);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.llength, &img.endian);
	return (img);
}

void	img_pixel_put(t_data *img, int x, int y, int colour)
{
	char	*dst;

	dst = img->addr + (y * img->llength + x * (img->bpp / 8));
	*(unsigned int *)dst = colour;
}

void	gen_imgage(t_prog *prog)
{
	int		x;
	int		y;
	int		colour;
	t_data	img;

	img = setup_img(prog);
	y = 0;
	while (y < prog->win.vert)
	{
		x = 0;
		while (x < prog->win.hori)
		{
			colour = calc_fractal(prog, x, y);
			img_pixel_put(&img, x, y, colour);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(prog->mlx, prog->win.win, img.img, 0, 0);
	mlx_destroy_image(prog->mlx, img.img);
}
