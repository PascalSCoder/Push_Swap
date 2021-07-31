/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   instruct.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/06 16:20:58 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/07/31 19:41:39 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/shared.h"
#include <stdio.h>
#include <unistd.h>

static t_bool	st_check_instr(char *instr, t_data *data, t_bool *is_ok)
{
	if (ft_strcmp(instr, "ra") == 0)
		*is_ok = stack_rotate_up(&data->a);
	else if (ft_strcmp(instr, "rb") == 0)
		*is_ok = stack_rotate_up(&data->b);
	else if (ft_strcmp(instr, "rr") == 0)
	{
		stack_rotate_up(&data->a);
		stack_rotate_up(&data->b);
		*is_ok = true;
	}
	else if (ft_strcmp(instr, "rra") == 0)
		*is_ok = stack_rotate_down(&data->a);
	else if (ft_strcmp(instr, "rrb") == 0)
		*is_ok = stack_rotate_down(&data->b);
	else if (ft_strcmp(instr, "rrr") == 0)
	{
		stack_rotate_down(&data->a);
		stack_rotate_down(&data->b);
		*is_ok = true;
	}
	else
		return (false);
	return (true);
}

void	instruct(char *instr, t_data *data)
{
	t_bool	is_valid;
	t_bool	is_ok;

	is_ok = false;
	is_valid = true;
	if (ft_strcmp(instr, "pa") == 0)
		is_ok = stack_push(&data->b, &data->a);
	else if (ft_strcmp(instr, "pb") == 0)
		is_ok = stack_push(&data->a, &data->b);
	else if (ft_strcmp(instr, "sa") == 0)
		is_ok = stack_swap(&data->a);
	else if (ft_strcmp(instr, "sb") == 0)
		is_ok = stack_swap(&data->b);
	else if (ft_strcmp(instr, "ss") == 0)
	{
		stack_swap(&data->a);
		stack_swap(&data->b);
		is_ok = true;
	}
	else if (st_check_instr(instr, data, &is_ok) == false)
		is_valid = false;
	if (!is_valid && data->is_checker)
		exit_error(data);
	if (is_ok && data->is_checker == false)
		ft_putendl_fd(instr, 1);
}
