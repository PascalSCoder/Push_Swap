/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack_rotate_down.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/06 14:20:32 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/07/30 00:02:08 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/shared.h"
#include <stdio.h>

t_bool	stack_rotate_down(t_stack *st)
{
	t_node	*node;

	if (!st->top || !st->top->prev)
		return (false);
	node = node_pop_bot(st);
	node_push_top(st, node);
	return (true);
}
