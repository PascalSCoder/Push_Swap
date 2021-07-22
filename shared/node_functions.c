/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   node_functions.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/06 12:14:07 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/06/13 15:41:23 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/shared.h"

void	node_push_bot(t_stack *stack, t_node *node)
{
	if (stack->bot)
		stack->bot->prev = node;
	if (!stack->top)
		stack->top = node;
	node->next = stack->bot;
	node->prev = 0;
	stack->bot = node;
}

void	node_push_top(t_stack *stack, t_node *node)
{
	if (stack->top)
		stack->top->next = node;
	if (!stack->bot)
		stack->bot = node;
	node->prev = stack->top;
	node->next = 0;
	stack->top = node;
}

t_node	*node_pop_top(t_stack *stack)
{
	t_node	*node;

	if (!stack->top)
		return (0);
	node = stack->top;
	if (stack->top->prev)
		stack->top->prev->next = 0;
	else
		stack->bot = 0;
	stack->top = stack->top->prev;
	return (node);
}

t_node	*node_pop_bot(t_stack *stack)
{
	t_node	*node;

	if (!stack->bot)
		return (0);
	node = stack->bot;
	if (stack->bot->next)
		stack->bot->next->prev = 0;
	else
		stack->top = 0;
	stack->bot = stack->bot->next;
	return (node);
}
