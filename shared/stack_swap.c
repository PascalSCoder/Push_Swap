/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack_swap.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/05 18:17:39 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/07/30 00:01:55 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/shared.h"
#include <stdio.h>

/*
	Switch the two nodes at the top of stack.
	Sets the top (and bot if neccesary) references of the stack correctly.
*/
t_bool	stack_swap(t_stack *st)
{
	t_node	*old_top;
	t_node	*new_top;

	if (!st->top || !st->top->prev)
		return (false);
	old_top = node_pop_top(st);
	new_top = node_pop_top(st);
	node_push_top(st, old_top);
	node_push_top(st, new_top);
	if (st->bot == new_top)
		st->bot = old_top;
	return (true);
}
