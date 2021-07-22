/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   is_sorted.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/07 17:14:51 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/07/17 12:59:41 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/shared.h"

t_bool	is_sorted(t_stack *stack)
{
	t_node	*node;

	node = stack->top;
	while (node && node->prev)
	{
		if (node->num.mask > node->prev->num.mask)
			return (false);
		node = node->prev;
	}
	return (true);
}

// t_bool	is_sorted_state(t_stack *stack, int state)
// {
// 	t_node	*node;
// 	t_node	*prev;

// 	node = stack->top;
// 	while (node && node->prev)
// 	{
// 		if (node->num.state == state)
// 		{
// 			prev = node->prev;
// 			// check prev nodes, until another state = met?
// 			// maybe add a flag to t_node like is_rotated, to compare correctly?
// 		}
// 	}
// 	return (true);
// }
