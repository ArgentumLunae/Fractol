/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fractol.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mteerlin <mteerlin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/18 16:43:52 by mteerlin      #+#    #+#                 */
/*   Updated: 2021/08/24 18:38:16 by mteerlin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include <stdbool.h>
# define MAX_ITER 1000
# define TRANS_FACT 0.1
# define ZOOM_FACT 1.05
# define FRACT_SHIFT 0.01
# define STD_REAL 0
# define STD_IMAG 0

typedef struct s_win
{
	void	*win;
	int		hori;
	int		vert;
	double	ar;
}	t_win;

typedef struct s_complex
{
	double	real;
	double	imag;
}	t_complex;

typedef struct s_args
{
	int		argc;
	char	**argv;
}	t_args;

typedef struct s_prog
{
	void		*mlx;
	t_win		win;
	double		zoom;
	t_complex	offset;
	t_complex	args;
	char		**argv;
	int			keyheld;
}	t_prog;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bpp;
	int		llength;
	int		endian;
}	t_data;

void		check_arguments(int argc, char **argv);
t_complex	get_complex_comp(int argc, char **argv);

t_prog		setup_mlx(int x, int y, int argc, char **argv);
void		events_mlx(t_prog *prog);
void		translate(int keycode, t_prog *prog);
void		alter_fractal(int keycode, t_prog *prog);
void		reset_transform(t_prog *prog);
void		get_translation(t_prog *prog, int x, int y);

void		gen_imgage(t_prog *prog);
int			calc_fractal(t_prog *prog, int x, int y);

#endif
