/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   is_sorted.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/07 17:14:51 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/07/29 23:03:54 by pspijkst      ########   odam.nl         */
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
