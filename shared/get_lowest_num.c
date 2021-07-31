/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_lowest_num.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/07 15:46:00 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/07/30 00:05:47 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/shared.h"

/*
	Returns the node with specified state, holding the lowest number;
*/
t_node	*node_lowest_state(t_stack *stack, int state)
{
	t_node	*node;
	t_node	*lowest;

	lowest = 0;
	node = stack->top;
	while (node)
	{
		if (node->num.state == state)
			if (!lowest || lowest->num.mask > node->num.mask)
				lowest = node;
		node = node->prev;
	}
	return (lowest);
}

/*
	Returns the node with specified state, holding the highest number;
*/
t_node	*node_highest_state(t_stack *stack, int state)
{
	t_node	*node;
	t_node	*highest;

	highest = 0;
	node = stack->top;
	while (node)
	{
		if (node->num.state == state)
			if (!highest || highest->num.mask < node->num.mask)
				highest = node;
		node = node->prev;
	}
	return (highest);
}

/*
	Returns the node holding highest number in t_stack.
*/
t_node	*node_highest(t_stack *stack)
{
	t_node	*node;
	t_node	*highest;

	highest = stack->top;
	if (!highest)
		return (0);
	node = highest->prev;
	while (node)
	{
		if (node->num.mask > highest->num.mask)
			highest = node;
		node = node->prev;
	}
	return (highest);
}

/*
	Returns the total amount of nodes in t_stack.
*/
int	node_count(t_stack *stack)
{
	t_node	*node;
	int		i;

	i = 0;
	node = stack->bot;
	while (node)
	{
		node = node->next;
		i++;
	}
	return (i);
}

/*
	Returns the amount of nodes in t_stack, with the specified state level.
*/
int	node_count_state(t_stack *stack, int state)
{
	t_node	*node;
	int		i;

	i = 0;
	node = stack->bot;
	while (node)
	{
		if (node->num.state == state)
			i++;
		node = node->next;
	}
	return (i);
}
