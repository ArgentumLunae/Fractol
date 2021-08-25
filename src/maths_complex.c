/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   maths_complex.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mteerlin <mteerlin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/25 13:43:04 by mteerlin      #+#    #+#                 */
/*   Updated: 2021/08/25 16:55:51 by mteerlin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../hdr/fractol.h"
#include <math.h>

t_complex	calc_polynomial(t_complex z)
{
	t_complex	res;

	res.real = pow(z.real, 3) - 3 * pow(z.real, 2) - 1;
	res.imag = 3 * pow(z.real, 2) * z.imag + pow(z.imag, 3);
	return (res);
}

t_complex	calc_polyprime(t_complex z)
{
	t_complex	res;

	res.real = 3 * (pow(z.real, 2) - pow(z.imag, 2));
	res.imag = 6 * z.real * z.imag;
	return (res);
}

t_complex	complex_div(t_complex num, t_complex denum)
{
	t_complex	div;

	div.real = num.real * denum.real + num.imag * denum.imag;
	div.real /= (denum.real * denum.real + denum.imag * denum.imag);
	div.imag = num.imag * denum.real - denum.imag * num.real;
	div.imag /= (denum.real * denum.real + denum.imag * denum.imag);
	return (div);
}
