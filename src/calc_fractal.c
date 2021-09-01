/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   calc_fractal.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mteerlin <mteerlin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/20 11:42:19 by mteerlin      #+#    #+#                 */
/*   Updated: 2021/09/01 11:55:22 by mteerlin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/libft/libft.h"
#include "../hdr/fractol.h"
#include <math.h>
#include <stdio.h>

unsigned int	mandelbrot(t_complex args, t_complex z, unsigned int iter)
{
	unsigned int	cnt;
	t_complex		c;
	t_complex		sq;

	c = args;
	c = z;
	sq.real = z.real * z.real;
	sq.imag = z.imag * z.imag;
	cnt = 0;
	while ((sq.real + sq.imag) < 4 && cnt < iter)
	{
		z.imag = 2 * z.real * z.imag + c.imag;
		z.real = sq.real - sq.imag + c.real;
		sq.real = z.real * z.real;
		sq.imag = z.imag * z.imag;
		cnt++;
	}
	return (cnt);
}

unsigned int	julia(t_complex args, t_complex z, unsigned int iter)
{
	unsigned int	cnt;
	t_complex		c;
	t_complex		sq;

	c = args;
	sq.real = z.real * z.real;
	sq.imag = z.imag * z.imag;
	cnt = 0;
	while ((sq.real + sq.imag) < 4 && cnt < iter)
	{
		z.imag = 2 * z.real * z.imag + c.imag;
		z.real = sq.real - sq.imag + c.real;
		sq.real = z.real * z.real;
		sq.imag = z.imag * z.imag;
		cnt++;
	}
	return (cnt);
}

unsigned int	shipwreck(t_complex args, t_complex z, unsigned int iter)
{
	unsigned int	cnt;
	t_complex		c;
	t_complex		sq;

	c = args;
	c = z;
	c.imag *= -1;
	sq.real = z.real * z.real;
	sq.imag = z.imag * z.imag;
	cnt = 0;
	while ((sq.real + sq.imag) < 4 && cnt < iter)
	{
		complex_abs(&z);
		z.imag = 2 * z.real * z.imag + c.imag;
		z.real = sq.real - sq.imag + c.real;
		sq.real = z.real * z.real;
		sq.imag = z.imag * z.imag;
		cnt++;
	}
	return (cnt);
}

void	calc_complex_coords(t_complex *c, t_prog *prog, int x, int y)
{
	c->real = ((2 * prog->win.ar) / prog->zoom);
	c->real *= ((2 * ((long double)x + 0.5)) / prog->win.hori - 1);
	c->real += prog->offset.real;
	c->imag = -(2 / prog->zoom);
	c->imag *= ((2 * ((long double)y + 0.5)) / prog->win.vert - 1);
	c->imag += prog->offset.imag;
}

int	calc_fractal(t_prog *prog, int x, int y)
{
	unsigned int	depth;
	t_complex		c;

	calc_complex_coords(&c, prog, x, y);
	depth = (prog->setfunc)(prog->args, c, prog->iter);
	if (depth == prog->iter)
		return (0);
	return (get_colour(depth));
}
