/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   calc_fractal.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mteerlin <mteerlin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/20 11:42:19 by mteerlin      #+#    #+#                 */
/*   Updated: 2021/08/24 17:16:54 by mteerlin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/libft/libft.h"
#include "../hdr/fractol.h"
#include <math.h>
#include <stdio.h>

int	mandelbrot(double real, double imag)
{
	int			cnt;
	t_complex	z;
	t_complex	sq;

	z.real = real;
	z.imag = imag;
	sq.real = real * real;
	sq.imag = imag * imag;
	cnt = 0;
	while ((sq.real + sq.imag) < 4 && cnt < MAX_ITER)
	{
		z.imag = 2 * z.real * z.imag + imag;
		z.real = sq.real - sq.imag + real;
		sq.real = z.real * z.real;
		sq.imag = z.imag * z.imag;
		cnt++;
	}
	return (cnt);
}

int	julia(t_complex args, t_complex z)
{
	int			cnt;
	t_complex	c;
	t_complex	sq;

	c = args;
	sq.real = z.real * z.real;
	sq.imag = z.imag * z.imag;
	cnt = 0;
	while ((sq.real + sq.imag) < 4 && cnt < MAX_ITER)
	{
		z.imag = 2 * z.real * z.imag + c.imag;
		z.real = sq.real - sq.imag + c.real;
		sq.real = z.real * z.real;
		sq.imag = z.imag * z.imag;
		cnt++;
	}
	return (cnt);
}

int	calc_fractal(t_prog *prog, int x, int y)
{
	int			depth;
	t_complex	c;

	c.real = ((2 * prog->win.ar) / prog->zoom);
	c.real *= ((2 * ((double)x + 0.5)) / prog->win.hori - 1);
	c.real += prog->offset.real;
	c.imag = (2 / prog->zoom);
	c.imag *= ((2 * ((double)y + 0.5)) / prog->win.vert - 1);
	c.imag += prog->offset.imag;
	if (!ft_strncmp(prog->argv[1], "mandelbrot", 11))
	{
		depth = mandelbrot(c.real, c.imag);
		if (depth == MAX_ITER)
			return (0);
		else
			return (0xfeffff80 * depth / MAX_ITER + 0x00000080);
	}
	else if (!ft_strncmp(prog->argv[1], "julia", 6))
	{
		depth = julia(prog->args, c);
		return (0xfeffff80 * depth / MAX_ITER + 0x00000080);
	}
	return (-1);
}
