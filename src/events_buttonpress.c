/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   events_buttonpress.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: mteerlin <mteerlin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/24 16:10:21 by mteerlin      #+#    #+#                 */
/*   Updated: 2021/08/26 17:44:07 by mteerlin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../hdr/fractol.h"
#include <limits.h>
#include <math.h>

void	get_translation(t_prog *prog, int x, int y)
{
	t_complex	trans;

	trans.real = ((2 * prog->win.ar) / prog->zoom);
	trans.real -= (2 * prog->win.ar) / (ZOOM_FACT * prog->zoom);
	trans.real *= (2 * ((long double)x + 0.5)) / prog->win.hori - 1;
	trans.imag = -(2 / prog->zoom) + (2 / (ZOOM_FACT * prog->zoom));
	trans.imag *= (2 * ((long double)y + 0.5)) / prog->win.vert - 1;
	prog->offset.real += trans.real;
	prog->offset.imag += trans.imag;
}

void	increment_iterations(t_prog *prog)
{
	unsigned int	additer;

	additer = BASE_ITER * ((prog->zoom - 1) / (sqrt(prog->zoom)));
	if (additer > UINT_MAX - BASE_ITER)
		prog->iter = UINT_MAX;
	else
		prog->iter = BASE_ITER + additer;
}
