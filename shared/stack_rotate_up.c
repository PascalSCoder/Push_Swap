/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack_rotate_up.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/06 14:19:10 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/07/30 00:02:02 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/shared.h"
#include <stdio.h>

t_bool	stack_rotate_up(t_stack *st)
{
	t_node	*node;

	if (!st->top || !st->top->prev)
		return (false);
	node = node_pop_top(st);
	node_push_bot(st, node);
	return (true);
}
