/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/06 12:45:46 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/07/17 13:37:14 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/shared.h"
#include <stdio.h>
#include <stdlib.h>

void	divide_state(t_data *data, t_state state);
int		divide(t_data *data, int state);



static void	a_to_b(t_data *data, int group)
{
	if (group == 0) // Small numbers
	{
		instruct(push, stack_a, data);
		instruct(rev_rotate, stack_b, data);
	}
	else if (group == 1) // Medium numbers
		instruct(push, stack_a, data);
	else // High numbers
		instruct(rev_rotate, stack_a, data);
}

static void	b_to_a(t_data *data, int group)
{
	if (group == 0) // Small numbers
		instruct(rev_rotate, stack_b, data);
	else if (group == 1) // Medium numbers
	{
		instruct(push, stack_b, data);
		instruct(rev_rotate, stack_a, data);
	}
	else // High numbers
		instruct(push, stack_b, data);
}

void	split_nums(t_data *data, t_stack *st, t_state state, int nums_to_move)
{
	int		lowest_num;
	int		slope;
	int		group;
	t_num	*num;

	lowest_num = node_lowest_state(st, state.base + state.substate)->num.mask;
	slope = nums_to_move / 3;
	while (st->top != NULL && st->top->num.state == state.base + state.substate)
	{
		num = &st->top->num;
		// printf("nums to move: %d, lowest: %d, slope: %d\n", nums_to_move, lowest_num, slope);
		group = (num->mask - lowest_num) / slope;
		if (group > 2)
			group = 2;
		num->state = state.base + STATE_OFFSET + group;
		if (st->id == stack_a)
			a_to_b(data, group);
		else
			b_to_a(data, group);
	}
}

void	divide_state(t_data *data, t_state state)
{
	t_stack	*st;
	t_num	*num;
	int		nums_to_move;

	state.substate = 2;
	while (state.substate >= 0)
	{
		st = get_stack_with_state(data, state.base + state.substate);
		if (st != NULL)
		{
			nums_to_move = node_count_state(st, state.base + state.substate);
			if (nums_to_move > 2)
			{
				// printf("Splitting: %d\n", state.base + state.substate);
				// print_stacks(&data->a, &data->b);
				split_nums(data, st, state, nums_to_move);
				divide(data, state.base + STATE_OFFSET);
			}
			else if (state.base != 0)
			{
				// printf("Nothing to divide for: %d\n", state.base + state.substate);
				sort_back(data, st);
			}
		}
		state.substate--;
	}
}

int	divide(t_data *data, int state)
{
	// printf("New state: %d\n", state);
	// print_stacks(&data->a, &data->b);
	divide_state(data, (t_state){.base = state});
	// sort_back(data, state);
	return (state);
}

int	main(int argc, char **argv)
{
	t_data	data;

	ft_memset(&data, 0, sizeof(t_data));
	data.b.id = stack_b;
	parse_stack(argc, argv, &data);
	// printf("Nodes have been created.\n");
	divide(&data, 0);
	// print_stacks(&data.a, &data.b);
}
