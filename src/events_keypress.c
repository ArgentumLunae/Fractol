/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   events_keypress.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: mteerlin <mteerlin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/23 14:41:07 by mteerlin      #+#    #+#                 */
/*   Updated: 2021/08/23 16:30:38 by mteerlin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../hdr/fractol.h"
#include "../hdr/keycodes.h"

void	arrowkeys(int keycode, t_prog *prog)
{
	if (keycode == LEFT)
		prog->offset.real -= 0.1 / prog->zoom;
	if (keycode == UP)
		prog->offset.imag += 0.1 / prog->zoom;
	if (keycode == RIGHT)
		prog->offset.real += 0.1 / prog->zoom;
	if (keycode == DOWN)
		prog->offset.imag -= 0.1 / prog->zoom;
	gen_imgage(prog);
}
