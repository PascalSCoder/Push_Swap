/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack_push.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/05 18:03:20 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/07/30 00:02:11 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/shared.h"
#include <stdio.h>

t_bool	stack_push(t_stack *from, t_stack *to)
{
	t_node	*node;

	node = node_pop_top(from);
	if (!node)
		return (false);
	node_push_top(to, node);
	return (true);
}
