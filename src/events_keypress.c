/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   events_keypress.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: mteerlin <mteerlin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/23 14:41:07 by mteerlin      #+#    #+#                 */
/*   Updated: 2021/09/01 12:05:13 by mteerlin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../hdr/fractol.h"
#include "../hdr/keycodes.h"

void	translate(int keycode, t_prog *prog)
{
	if (keycode == K_LEFT)
		prog->offset.real -= 0.1 / prog->zoom;
	if (keycode == K_UP)
		prog->offset.imag += 0.1 / prog->zoom;
	if (keycode == K_RIGHT)
		prog->offset.real += 0.1 / prog->zoom;
	if (keycode == K_DOWN)
		prog->offset.imag -= 0.1 / prog->zoom;
	gen_imgage(prog);
}

void	alter_fractal(int keycode, t_prog *prog)
{
	if (keycode == K_NUMFOUR)
		prog->args.real -= (FRACT_SHIFT / prog->zoom);
	if (keycode == K_NUMSIX)
		prog->args.real += (FRACT_SHIFT / prog->zoom);
	if (keycode == K_NUMEIGHT)
		prog->args.imag += (FRACT_SHIFT / prog->zoom);
	if (keycode == K_NUMTWO)
		prog->args.imag -= (FRACT_SHIFT / prog->zoom);
	gen_imgage(prog);
}

void	reset_transform(t_prog *prog)
{
	prog->offset.real = 0;
	prog->offset.imag = 0;
	prog->zoom = 1;
	gen_imgage(prog);
}
