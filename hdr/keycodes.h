/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   keycodes.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mteerlin <mteerlin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/23 16:23:25 by mteerlin      #+#    #+#                 */
/*   Updated: 2021/08/23 16:27:19 by mteerlin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYCODES_H
# define KEYCODES_H
# ifdef __linux__
#  define ESC 65307
#  define UP 65362
#  define DOWN 65364
#  define LEFT 65361
#  define RIGHT 65363
# else
#  define ESC 53
# endif
#endif