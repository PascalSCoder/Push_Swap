/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_stack.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/23 13:51:27 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/07/31 19:42:48 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/shared.h"
#include <stdlib.h>

static int	strslen(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
		i++;
	return (i);
}

static t_bool	check_duplicate(int *ints, int new, int count, int totalcount)
{
	while (totalcount > count)
	{
		totalcount--;
		if (new == ints[totalcount])
			return (false);
	}
	return (true);
}

static int	*parse_ints(int count, char **strs, t_data *data)
{
	int	*ints;
	int	tmp;
	int	total_count;

	total_count = count;
	ints = ft_calloc(count, sizeof(int));
	if (!ints)
		exit_error(data);
	while (count > 0)
	{
		if (!ft_atoi_strict(*strs, &tmp))
			exit_error(data);
		else if (!check_duplicate(ints, tmp, count, total_count))
			exit_error(data);
		count--;
		strs++;
		ints[count] = tmp;
	}
	return (ints);
}

int	*handle_input(int argc, char **argv, t_data *data)
{
	int		count;
	int		*ints;
	char	**strs;

	strs = 0;
	if (argc == 2)
	{
		strs = ft_split(argv[1], ' ');
		if (!strs)
			exit_error(data);
		count = strslen(strs);
		argv = strs;
	}
	else
	{
		count = argc - 1;
		argv++;
	}
	if (count == 0)
		exit_error(data);
	data->num_c = count;
	ints = parse_ints(count, argv, data);
	if (strs)
		ft_split_free(strs);
	return (ints);
}

void	parse_stack(int argc, char **argv, t_data *data)
{
	int		*ints;
	t_node	*nodes;

	ints = handle_input(argc, argv, data);
	nodes = ints_to_nodes(ints, data->num_c);
	if (!nodes)
		exit_error(data);
	data->node_start = nodes;
	data->a.bot = nodes;
	while (nodes->next)
		nodes = nodes->next;
	data->a.top = nodes;
}
