/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   maths_complex.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mteerlin <mteerlin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/25 13:43:04 by mteerlin      #+#    #+#                 */
/*   Updated: 2021/09/01 12:06:11 by mteerlin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../hdr/fractol.h"
#include <float.h>

void	complex_abs(t_complex *c)
{
	if (c->real < 0 && c->real > -1 * LDBL_MAX)
		c->real *= -1;
	if (c->imag < 0 && c->imag > -1 * LDBL_MAX)
		c->imag *= -1;
}
