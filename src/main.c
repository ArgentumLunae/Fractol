/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mteerlin <mteerlin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/18 15:15:46 by mteerlin      #+#    #+#                 */
/*   Updated: 2021/08/23 13:38:58 by mteerlin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/libft/libft.h"
#include "../hdr/fractol.h"
#include <stdlib.h>

int	main(int argc, char **argv)
{
	t_prog	prog;

	check_arguments(argc, argv);
	prog = setup_mlx(500, 500, argc, argv);
	prog.args.argc = argc;
	prog.args.argv = argv;
	gen_imgage(&prog);
	events_mlx(&prog);
	return (0);
}
