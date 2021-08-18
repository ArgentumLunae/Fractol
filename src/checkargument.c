/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checkargument.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mteerlin <mteerlin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/18 16:42:38 by mteerlin      #+#    #+#                 */
/*   Updated: 2021/08/18 17:12:05 by mteerlin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/libft/libft.h"
#include <stdio.h>
#include <stdlib.h>

void	print_set_list(void)
{
	printf("supply which available fractal to display.\n");
	printf("1.\tmandelbrot\n2.\tjulia");
}

void	check_arguments(int argc, char **argv)
{
	if (argc < 2)
	{
		printf("No input argument found.\n");
		print_set_list();
		exit(EXIT_FAILURE);
	}
	else if (ft_strncmp(argv[1], "mandelbrot", 10) && \
				 ft_strncmp(argv[1], "julia", 4))
	{
		printf("imput argument not recognised.\n");
		print_set_list();
		exit(EXIT_FAILURE);
	}
}
