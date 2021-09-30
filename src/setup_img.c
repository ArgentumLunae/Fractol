/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   setup_img.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mteerlin <mteerlin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/18 20:02:37 by mteerlin      #+#    #+#                 */
/*   Updated: 2021/09/30 13:29:17 by mteerlin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../hdr/fractol.h"
#include "../incl/mlx/mlx.h"

void	img_pixel_put(t_data *img, int x, int y, int colour)
{
	char	*dst;

	dst = img->addr + (y * img->line + x * (img->bpp / 8));
	*(unsigned int *)dst = colour;
}

void	gen_imgage(t_prog *prog)
{
	int			x;
	int			y;
	int			colour;
	static int	i = 0;

	y = 0;
	while (y < prog->win.vert)
	{
		x = 0;
		while (x < prog->win.hori)
		{
			colour = calc_fractal(prog, x, y);
			img_pixel_put(&(prog->img[i]), x, y, colour);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(prog->mlx, prog->win.win, prog->img[i].img, 0, 0);
	if (i == 0)
		i = 1;
	else
		i = 0;
}
