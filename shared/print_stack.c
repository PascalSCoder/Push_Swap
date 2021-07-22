/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_stack.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/06 12:39:57 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/07/14 15:55:25 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/shared.h"
#include <stdio.h>

void	print_node(t_node *node)
{
	printf("[%3d](%2d)", node->num.mask, node->num.state);
}

void	print_stack(t_stack *stack)
{
	t_node	*tmp;

	tmp = stack->top;
	while (tmp)
	{
		print_node(tmp);
		printf("\n");
		tmp = tmp->prev;
	}
	printf("\n");
}

void	print_stacks(t_stack *a, t_stack *b)
{
	t_node	*a_tmp;
	t_node	*b_tmp;

	a_tmp = a->top;
	b_tmp = b->top;
	printf("\n");
	while (a_tmp || b_tmp)
	{
		if (a_tmp)
		{
			print_node(a_tmp);
			a_tmp = a_tmp->prev;
		}
		else
			printf("[   ]    ");
		printf("   ");
		if (b_tmp)
		{
			print_node(b_tmp);
			b_tmp = b_tmp->prev;
		}
		else
			printf("[   ]");
		printf("\n");
	}
}
