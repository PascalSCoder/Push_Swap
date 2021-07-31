/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   contains_state.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/07 16:54:12 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/07/30 16:57:17 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/shared.h"
#include <stdio.h>

t_bool	contains_state(t_stack *stack, int state)
{
	t_node	*node;

	node = stack->top;
	while (node)
	{
		if (node->num.state == state)
			return (true);
		node = node->prev;
	}
	return (false);
}

t_stack	*get_stack_with_state(t_data *data, int state)
{
	if (data->a.top && data->a.top->num.state == state)
		return (&data->a);
	else if (data->a.bot && data->a.bot->num.state == state)
	{
		while (data->a.bot->num.state == state)
			instruct("rra", data);
		return (&data->a);
	}
	else if (data->b.top && data->b.top->num.state == state)
		return (&data->b);
	else if (data->b.bot && data->b.bot->num.state == state)
	{
		while (data->b.bot->num.state == state)
			instruct("rrb", data);
		return (&data->b);
	}
	else
		return (NULL);
}
