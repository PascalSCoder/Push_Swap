/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack_rotate_up.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/06 14:19:10 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/06/06 17:06:44 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/shared.h"
#include <stdio.h>

void	stack_rotate_up(t_data *data, t_stackid id)
{
	t_stack	*stack;
	t_node	*node;

	if (id == stack_ab)
	{
		stack_rotate_up(data, stack_b);
		id = stack_a;
	}
	stack = get_stack(data, id);
	if (!stack->top || !stack->top->prev)
	{
		data->fail_c += 1;
		printf("Error: rotate (up) with <= 1 nums!\n");
		return ;
	}
	node = node_pop_top(stack);
	node_push_bot(stack, node);
}
