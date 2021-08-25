/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mteerlin <mteerlin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/18 15:15:46 by mteerlin      #+#    #+#                 */
/*   Updated: 2021/08/25 11:07:08 by mteerlin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/libft/libft.h"
#include "../hdr/fractol.h"
#include <stdlib.h>

int	main(int argc, char **argv)
{
	t_prog	prog;

	check_arguments(argc, argv);
	prog = setup_mlx(640, 360, argc, argv);
	gen_imgage(&prog);
	events_mlx(&prog);
	return (0);
}
