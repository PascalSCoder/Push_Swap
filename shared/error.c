/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/06 13:10:11 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/07/30 00:07:00 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/shared.h"
#include <stdlib.h>

/*
	Prints "Error\n" and exits the program.
*/
void	exit_error(void)
{
	ft_putendl_fd("Error", 1);
	exit(0);
}
