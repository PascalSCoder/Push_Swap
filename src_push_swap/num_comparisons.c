/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   num_comparisons.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/07/16 21:50:44 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/07/16 21:52:55 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/shared.h"

t_bool	num_state_isequal(t_num *num1, t_num *num2)
{
	if (num1->state == num2->state)
		return (true);
	return (false);
}

t_bool	num_ishigher(t_num *num1, t_num *num2)
{
	if (num1->mask > num2->mask)
		return (true);
	return (false);
}
