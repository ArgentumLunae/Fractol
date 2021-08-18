/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fractol.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mteerlin <mteerlin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/18 16:43:52 by mteerlin      #+#    #+#                 */
/*   Updated: 2021/08/18 19:35:10 by mteerlin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include <stdbool.h>

typedef struct s_win
{
	void	*win;
	int		hori;
	int		vert;
}	t_win;

typedef struct s_prog
{
	void	*mlx;
	t_win	win;
}	t_prog;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bpp;
	int		llength;
	int		endian;
}	t_data;

void	check_arguments(int argc, char **argv);

t_prog	setup_mlx(int x, int y, char *name);
void	events_mlx(t_prog *prog);

#endif
