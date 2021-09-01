/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fractol.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mteerlin <mteerlin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/18 16:43:52 by mteerlin      #+#    #+#                 */
/*   Updated: 2021/09/01 12:09:17 by mteerlin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# define BASE_ITER 32
# define TRANS_FACT 0.1
# define ZOOM_FACT 1.5
# define FRACT_SHIFT 0.05
# define STD_REAL 0
# define STD_IMAG 0

typedef struct s_win
{
	void		*win;
	int			hori;
	int			vert;
	long double	ar;
}	t_win;

typedef struct s_complex
{
	long double	real;
	long double	imag;
}	t_complex;

typedef unsigned int	(*t_setfunc)\
	(t_complex args, t_complex c, unsigned int iter);

typedef struct s_prog
{
	void			*mlx;
	t_win			win;
	long double		zoom;
	t_complex		offset;
	t_complex		args;
	t_setfunc		setfunc;
	int				setindex;
	unsigned int	iter;
	int				keyheld;
}	t_prog;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bpp;
	int		llength;
	int		endian;
}	t_data;

void			check_arguments(int argc, char **argv);
t_complex		get_complex_comp(int argc, char **argv);

t_prog			setup_mlx(int x, int y, int argc, char **argv);
void			events_mlx(t_prog *prog);
void			translate(int keycode, t_prog *prog);
void			alter_fractal(int keycode, t_prog *prog);
void			reset_transform(t_prog *prog);
void			get_translation(t_prog *prog, int x, int y);
void			increment_iterations(t_prog *prog);

void			gen_imgage(t_prog *prog);
int				calc_fractal(t_prog *prog, int x, int y);
unsigned int	mandelbrot(t_complex args, t_complex z, unsigned int iter);
unsigned int	julia(t_complex args, t_complex z, unsigned int iter);
unsigned int	shipwreck(t_complex args, t_complex z, unsigned int iter);

void			complex_abs(t_complex *c);

int				get_colour(int	depth);

#endif
