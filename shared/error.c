/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/06 13:10:11 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/06/06 17:13:14 by pspijkst      ########   odam.nl         */
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

void	exit_error_debug(char *msg)
{
	ft_putendl_fd("Error", 1);
	ft_putendl_fd(msg, 1);
	exit(0);
}
