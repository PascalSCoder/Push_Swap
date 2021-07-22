/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ints_to_nodes.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/20 12:44:02 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/07/17 13:28:58 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/shared.h"
#include <stdlib.h>
#include <stdio.h>

static t_node	*init_nodes(int count)
{
	t_node	*nodes;
	int	i;

	nodes = ft_calloc(count, sizeof(t_node));
	if (!nodes)
		return (0);
	i = 0;
	while (i < count)
	{
		if (i != count - 1)
			nodes[i].next = nodes + i + 1;
		if (i != 0)
			nodes[i].prev = nodes + i - 1;
		nodes[i].num.mask = -1;
		i++;
	}
	return (nodes);
}

static void	set_masks(t_node *nodes, int *ints, int count)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	while (i < count)
	{
		k = 0;
		j = 0;
		while (k < count)
		{
			if (nodes[k].num.mask != -1)
			{
				if (ints[i] < nodes[k].num.value)
					nodes[k].num.mask++;
				else
					j++;;
			} 
			k++;
		}
		nodes[i].num.mask = j;
		nodes[i].num.value = ints[i];
		i++;
	}
}

t_node	*ints_to_nodes(int *ints, int count)
{
	t_node	*nodes;

	nodes = init_nodes(count);
	if (!nodes)
		return (0);
	set_masks(nodes, ints, count);
	free(ints);
	return (nodes);
}
