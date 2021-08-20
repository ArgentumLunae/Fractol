/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   calc_fractal.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mteerlin <mteerlin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/20 11:42:19 by mteerlin      #+#    #+#                 */
/*   Updated: 2021/08/20 16:12:33 by mteerlin      ########   odam.nl         */
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

int	julia(char **argv, double real, double imag)
{
	int			cnt;
	t_complex	c;
	t_complex	sq;

	c.real = ft_atof(argv[2]);
	c.imag = ft_atof(argv[3]);
	sq.real = real * real;
	sq.imag = imag * imag;
	cnt = 0;
	while ((sq.real + sq.imag) < 4 && cnt < MAX_ITER)
	{
		imag = 2 * real * imag + c.imag;
		real = sq.real - sq.imag + c.real;
		sq.real = real * real;
		sq.imag = imag * imag;
		cnt++;
	}
	return (cnt);
}

int	calc_fractal(t_prog *prog, int x, int y)
{
	int			depth;
	t_complex	c;

	c.real = (2.5 / prog->zoom) * ((2 * (double)x) / prog->win.hori - 1);
	c.imag = -(2.5 / prog->zoom) * ((2 * (double)y) / prog->win.vert - 1);
	if (!ft_strncmp(prog->argv[1], "mandelbrot", 11))
	{
		depth = mandelbrot(c.real, c.imag);
		if (depth == MAX_ITER)
			return (0);
		else
			return (0x000060 + ((5 * depth) % 0xffffa0));
	}
	else if (!ft_strncmp(prog->argv[1], "julia", 6))
	{
		depth = julia(prog->argv, c.real, c.imag);
		return (0x000060 + ((5 * depth) % 0xffffa0));
	}
	return (-1);
}
