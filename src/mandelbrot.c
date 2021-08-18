/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mandelbrot.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mteerlin <mteerlin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/07/28 15:30:31 by mteerlin      #+#    #+#                 */
/*   Updated: 2021/08/16 12:30:16 by mteerlin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <math.h>

bool	mandelbrot(double real, double complex)
{
	int	cnt;

	if (complex == 0 && real > 0.25)
		return (false);
	cnt = 0;
	while (cnt < 100000)
	{
		if (sqrt(pow(real, 2) + pow(complex, 2)) > 2)
			return (false);
		real = pow(real, 2) + pow(complex, 2) + real;
		complex = (2 * real + 1) * complex;
		cnt++;
	}
	return (true);
}
