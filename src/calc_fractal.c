/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   calc_fractal.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mteerlin <mteerlin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/20 11:42:19 by mteerlin      #+#    #+#                 */
/*   Updated: 2021/08/23 14:59:11 by mteerlin      ########   odam.nl         */
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

t_complex	get_complex_comp(t_args *args)
{
	t_complex	ret;

	if (args->argc < 3)
	{
		ret.real = STD_REAL;
		ret.imag = STD_IMAG;
	}
	else if (args->argc < 4)
	{
		ret.real = ft_atoi(args->argv[2]);
		ret.imag = STD_IMAG;
	}
	else
	{
		ret.real = ft_atof(args->argv[2]);
		ret.imag = ft_atof(args->argv[3]);
	}
	return (ret);
}

int	julia(t_args *args, t_complex z)
{
	int			cnt;
	t_complex	c;
	t_complex	sq;

	c = get_complex_comp(args);
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

	c.real = (2 / prog->zoom) * ((2 * (double)x) / prog->win.hori - 1);
	c.real += prog->offset.real;
	c.imag = -(2 / prog->zoom) * ((2 * (double)y) / prog->win.vert - 1);
	c.imag += prog->offset.imag;
	if (!ft_strncmp(prog->args.argv[1], "mandelbrot", 11))
	{
		depth = mandelbrot(c.real, c.imag);
		if (depth == MAX_ITER)
			return (0);
		else
			return (0x000060 + ((5 * depth) % 0xffffa0));
	}
	else if (!ft_strncmp(prog->args.argv[1], "julia", 6))
	{
		depth = julia(&prog->args, c);
		return (0x000060 + ((5 * depth) % 0xffffa0));
	}
	return (-1);
}
