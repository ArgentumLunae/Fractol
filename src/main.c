/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mteerlin <mteerlin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/18 15:15:46 by mteerlin      #+#    #+#                 */
/*   Updated: 2021/09/01 12:03:45 by mteerlin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../hdr/fractol.h"

int	main(int argc, char **argv)
{
	t_prog	prog;

	check_arguments(argc, argv);
	prog = setup_mlx(640, 360, argc, argv);
	gen_imgage(&prog);
	events_mlx(&prog);
	return (0);
}
