/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_counters.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/06 22:47:41 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/06/07 17:06:22 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/shared.h"
#include <stdio.h>

void	print_counters(t_data *data)
{
	printf("                  Pushes: %d\n", data->push_c);
	printf("          Swaps (single): %d\n", data->swap_c);
	printf("        Rotates (single): %d\n", data->rotdown_c);
	printf("Reverse rotates (single): %d\n", data->rotup_c);
	printf("          Swaps (double): %d\n", data->d_swap_c);
	printf("        Rotates (double): %d\n", data->d_rotdown_c);
	printf("Reverse rotates (double): %d\n", data->d_rotup_c);
	printf("                          ___\n");
	printf("                   Total: %d\n", data->push_c + data->swap_c + data->rotdown_c + data->rotup_c + data->d_swap_c + data->d_rotdown_c + data->d_rotup_c);
	printf("     Failed instructions: %d\n", data->fail_c);
}
