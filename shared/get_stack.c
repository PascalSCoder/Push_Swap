/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_stack.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/06 14:48:57 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/06/06 16:44:13 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/shared.h"

t_stack	*get_stack(t_data *data, t_stackid id)
{
	if (id == stack_a || id == stack_b)
		return ((t_stack *)data + id);
	return (0);
}
