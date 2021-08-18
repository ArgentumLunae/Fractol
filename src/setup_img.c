/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   setup_img.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mteerlin <mteerlin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/18 20:02:37 by mteerlin      #+#    #+#                 */
/*   Updated: 2021/08/18 20:09:30 by mteerlin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../hdr/fractol.h"
#include "../incl/mlx/mlx.h"

t_data	setup_img(t_prog *prog)
{
	t_data	img;

	img.img = mlx_new_imgage(prog->mlx, prog->win.hori, prog->win.vert);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.llength, &img.endian);
	return (img);
}

void	gen_imgage(t_prog *prog)
{
	int	x;
	int	y;
	int	colour;
}