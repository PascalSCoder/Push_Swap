/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack_push.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/05 18:03:20 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/06/13 15:50:50 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/shared.h"
#include <stdio.h>

void	stack_push(t_data *data, t_stackid id)
{
	t_stack	*from;
	t_stack	*to;
	t_node	*node;

	from = get_stack(data, id);
	if (id == stack_a)
		to = get_stack(data, stack_b);
	else
		to = get_stack(data, stack_a);
	node = node_pop_top(from);
	if (!node)
	{
		printf("ERROR: Cannot push from empty stack!\n");
		data->fail_c += 1;
		return ;
	}
	node_push_top(to, node);
}
