/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_back.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/07/16 21:54:50 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/07/30 16:59:02 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/shared.h"
#include <stdio.h>

static void	st_get_nums(t_stack *st, t_num **num1, t_num **num2)
{
	*num1 = &st->top->num;
	if (st->top->prev && st->top->prev->num.state == (*num1)->state)
	{
		*num2 = &st->top->prev->num;
		(*num2)->state = 0;
	}
	else
		*num2 = 0;
	(*num1)->state = 0;
}

void	sort_back(t_data *data, t_stack *st)
{
	t_num	*num1;
	t_num	*num2;

	st_get_nums(st, &num1, &num2);
	if (st->id == stack_a)
	{
		if (num2 != NULL && num_ishigher(num1, num2))
			instruct("sa", data);
	}
	else
	{
		if (num2 != NULL)
		{
			if (num_ishigher(num2, num1))
				instruct("sb", data);
			instruct("pa", data);
		}
		instruct("pa", data);
	}
}
