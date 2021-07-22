/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack_rotate_down.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/06 14:20:32 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/06/06 17:06:48 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/shared.h"
#include <stdio.h>

void	stack_rotate_down(t_data *data, t_stackid id)
{
	t_stack	*stack;
	t_node	*node;

	if (id == stack_ab)
	{
		stack_rotate_down(data, stack_b);
		id = stack_a;
	}
	stack = get_stack(data, id);
	if (!stack->top || !stack->top->prev)
	{
		data->fail_c += 1;
		printf("Error: rotate (down) with <= 1 nums!\n");
		return ;
	}
	node = node_pop_bot(stack);
	node_push_top(stack, node);
}
