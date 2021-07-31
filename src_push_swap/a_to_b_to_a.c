/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   a_to_b_to_a.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/07/29 20:44:46 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/07/30 16:55:25 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/shared.h"

void	a_to_b(t_data *data, int group)
{
	if (group == 0)
	{
		instruct("pb", data);
		instruct("rb", data);
	}
	else if (group == 1)
		instruct("pb", data);
	else
		instruct("ra", data);
}

void	b_to_a(t_data *data, int group)
{
	if (group == 0)
		instruct("rb", data);
	else if (group == 1)
	{
		instruct("pa", data);
		instruct("ra", data);
	}
	else
		instruct("pa", data);
}
