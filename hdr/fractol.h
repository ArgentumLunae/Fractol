/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fractol.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mteerlin <mteerlin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/18 16:43:52 by mteerlin      #+#    #+#                 */
/*   Updated: 2021/08/20 16:04:14 by mteerlin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include <stdbool.h>
# define MAX_ITER 100

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
	double	zoom;
	char	**argv;
}	t_prog;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bpp;
	int		llength;
	int		endian;
}	t_data;

typedef struct s_complex
{
	double	real;
	double	imag;
}	t_complex;

void	check_arguments(int argc, char **argv);

t_prog	setup_mlx(int x, int y, char **argv);
void	events_mlx(t_prog *prog);

void	gen_imgage(t_prog *prog);
int		calc_fractal(t_prog *prog, int x, int y);

#endif
