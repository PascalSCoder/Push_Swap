/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/06 12:45:46 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/07/31 19:35:38 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/shared.h"
#include <stdio.h>
#include <stdlib.h>

static void	st_divide_state(t_data *data, t_state state);
static int	st_divide(t_data *data, int state);

static void	st_split_nums(t_data *data, t_stack *st, t_state state, int nums)
{
	int		lowest_num;
	int		slope;
	int		group;
	t_num	*num;

	lowest_num = node_lowest_state(st, state.base + state.substate)->num.mask;
	slope = nums / 3;
	while (st->top != NULL && st->top->num.state == state.base + state.substate)
	{
		num = &st->top->num;
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

static void	st_divide_state(t_data *data, t_state state)
{
	t_stack	*st;
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
				st_split_nums(data, st, state, nums_to_move);
				st_divide(data, state.base + STATE_OFFSET);
			}
			else if (state.base != 0)
				sort_back(data, st);
		}
		state.substate--;
	}
}

static int	st_divide(t_data *data, int state)
{
	st_divide_state(data, (t_state){.base = state});
	return (state);
}

int	main(int argc, char **argv)
{
	t_data	data;
	int		count;

	if (argc == 1)
		return (0);
	ft_memset(&data, 0, sizeof(t_data));
	data.b.id = stack_b;
	parse_stack(argc, argv, &data);
	count = node_count(&data.a);
	if (!is_sorted(&data.a))
	{
		if (count <= 5)
			sort_simple(&data, count);
		else
			st_divide(&data, 0);
	}
	free(data.node_start);
	return (0);
}
