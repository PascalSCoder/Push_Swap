/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/22 16:59:07 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/07/31 19:35:47 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/shared.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

static void	st_read_input(t_data *data)
{
	char	*line;

	while (get_next_line(0, &line) > 0)
	{
		instruct(line, data);
		free(line);
	}
	free(line);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc == 1)
		return (0);
	ft_memset(&data, 0, sizeof(t_data));
	data.is_checker = 1;
	data.b.id = stack_b;
	parse_stack(argc, argv, &data);
	st_read_input(&data);
	if (is_sorted(&data.a) && node_count(&data.b) == 0)
		ft_putendl_fd("OK", 1);
	else
		ft_putendl_fd("KO", 1);
	free(data.node_start);
	return (0);
}
