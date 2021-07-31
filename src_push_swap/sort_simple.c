/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_simple.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/07/28 13:36:15 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/07/30 16:56:45 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/shared.h"
#include <stdio.h>
#include <stdlib.h>

static void	st_push_back(t_data *data)
{
	if (data->b.top && data->b.top->prev && \
		num_ishigher(&data->b.top->prev->num, &data->b.top->num))
		instruct("sb", data);
	while (data->b.top)
		instruct("pa", data);
}

// 3 1 2
// 2 1 3
// 1 3 2
// 2 3 1
// 3 2 1
static void	st_sort_three(t_data *data)
{
	if (num_ishigher(&data->a.top->num, &data->a.top->prev->num) && \
			num_ishigher(&data->a.top->num, &data->a.bot->num) && \
			num_ishigher(&data->a.bot->next->num, &data->a.bot->num))
	{
		instruct("sa", data);
		instruct("rra", data);
	}
	else if (num_ishigher(&data->a.top->num, &data->a.top->prev->num) && \
			num_ishigher(&data->a.bot->num, &data->a.top->num))
		instruct("sa", data);
	else if (num_ishigher(&data->a.bot->next->num, &data->a.bot->num) && \
			num_ishigher(&data->a.top->prev->num, &data->a.top->num) && \
			num_ishigher(&data->a.bot->num, &data->a.top->num))
	{
		instruct("sa", data);
		instruct("ra", data);
	}
	else if (num_ishigher(&data->a.top->prev->num, &data->a.top->num) && \
			num_ishigher(&data->a.top->num, &data->a.bot->num))
		instruct("rra", data);
	else if (num_ishigher(&data->a.top->num, &data->a.top->prev->num) && \
			num_ishigher(&data->a.top->num, &data->a.bot->num) && \
			num_ishigher(&data->a.bot->num, &data->a.bot->next->num))
		instruct("ra", data);
}

void	sort_simple(t_data *data, int count)
{
	int	to_push;

	to_push = count - 3;
	if (data->a.top && data->a.top->prev)
	{
		while (count > 3)
		{
			if (data->a.top->num.mask < to_push)
			{
				instruct("pb", data);
				count--;
			}
			else
				instruct("rra", data);
		}
		if (count == 3)
			st_sort_three(data);
		else
			if (num_ishigher(&data->a.top->num, &data->a.bot->num))
				instruct("sa", data);
		if (data->b.top)
			st_push_back(data);
	}
}
