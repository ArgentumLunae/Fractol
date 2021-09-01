/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checkargument.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mteerlin <mteerlin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/18 16:42:38 by mteerlin      #+#    #+#                 */
/*   Updated: 2021/09/01 11:30:33 by mteerlin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/libft/libft.h"
#include "../hdr/fractol.h"
#include <stdio.h>
#include <stdlib.h>

void	print_set_list(void)
{
	printf("supply which available fractal to display.\n");
	printf("1.\tmandelbrot\n2.\tjulia\n3.\tshipwreck\n");
}

void	check_arguments(int argc, char **argv)
{
	if (argc < 2)
	{
		printf("No input argument found.\n");
		print_set_list();
		exit(EXIT_SUCCESS);
	}
	else if (ft_strncmp(argv[1], "mandelbrot", 11) && \
			ft_strncmp(argv[1], "julia", 6) && \
			ft_strncmp(argv[1], "shipwreck", 7))
	{
		printf("imput argument not recognised.\n");
		print_set_list();
		exit(EXIT_SUCCESS);
	}
}

t_complex	get_complex_comp(int argc, char **argv)
{
	t_complex	ret;

	if (argc < 3)
	{
		ret.real = STD_REAL;
		ret.imag = STD_IMAG;
	}
	else if (argc < 4)
	{
		ret.real = ft_atoi(argv[2]);
		ret.imag = STD_IMAG;
	}
	else
	{
		ret.real = ft_atof(argv[2]);
		ret.imag = ft_atof(argv[3]);
	}
	return (ret);
}
