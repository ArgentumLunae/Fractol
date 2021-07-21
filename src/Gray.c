/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Gray.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mteerlin <mteerlin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/07/21 12:25:03 by mteerlin      #+#    #+#                 */
/*   Updated: 2021/07/21 14:54:00 by mteerlin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/mlx/mlx.h"
#include "../incl/libft/libft.h"
#include <stdio.h>

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bpp;
	int		llength;
	int		endian;
}	t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->llength + x * (data->bpp / 8));
	*(unsigned int *)dst = color;
}

int	main(int argc, char **argv)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	int		shade;
	int		x;
	int		y;

	if (argc != 2)
	{
		printf("Error: 1 program argument required");
		return (0);
	}
	shade = ft_atoi(argv[1]) % 256;
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Gray");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.llength, &img.endian);
	y = 0;
	while (y < 1080)
	{
		x = 0;
		while (x < 1920)
		{
			my_mlx_pixel_put(&img, x, y, (shade + (shade << 8) + (shade << 16)));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
	return (0);
}
