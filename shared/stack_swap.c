/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack_swap.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/05 18:17:39 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/06/06 17:06:41 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/shared.h"
#include <stdio.h>

/*
	Switch the two nodes at the top of stack.
	Sets the top (and bot if neccesary) references of the stack correctly.
*/
void	stack_swap(t_data *data, t_stackid id)
{
	t_stack	*stack;
	t_node	*old_top;
	t_node	*new_top;

	if (id == stack_ab)
	{
		stack_swap(data, stack_b);
		id = stack_a;
	}
	stack = get_stack(data, id);
	if (!stack->top || !stack->top->prev)
	{
		printf("ERROR: Not enough items to swap!\n");
		data->fail_c += 1;
		return ;
	}
	old_top = node_pop_top(stack);
	new_top = node_pop_top(stack);
	node_push_top(stack, old_top);
	node_push_top(stack, new_top);
	if (stack->bot == new_top)
		stack->bot = old_top;
}
