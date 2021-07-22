/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   instruct.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/06 16:20:58 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/06/06 16:49:25 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/shared.h"

/*
	Enum order: p, s, r, rr
*/
static void	*get_func(t_instrkey key)
{
	static void	*funcs[] =\
	{
		stack_push,
		stack_swap,
		stack_rotate_down,
		stack_rotate_up
	};

	return (funcs[key]);
}

static int	*get_counter(t_instrkey key, t_stackid id, t_data *data)
{
	int	*counter;

	counter = &(data->push_c) + key;
	if (id == stack_ab)
		counter += 3;
	return (counter);
}

/*
	Perform an instruction on the stack(s).
	Supply instruction key and stack_id (see enums for options).
	(for push, stack_id represents the 'from' stack)
*/
void	instruct(t_instrkey key, t_stackid id, t_data *data)
{
	void	(*func)(t_data *, t_stackid);
	int		*counter;

	func = get_func(key);
	counter = get_counter(key, id, data);
	write_instr(key, id);
	*counter += 1;
	func(data, id);
}
