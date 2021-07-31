/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi_strict.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/29 21:57:42 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/07/31 19:34:54 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/shared.h"
#include <stdlib.h>

static char	check_overflow(int prev, int new)
{
	if (new < prev)
		return (true);
	else
		return (false);
}

char	ft_atoi_strict(char *str, int *out_num)
{
	char	negative;
	int		prev;
	int		i;

	*out_num = 0;
	negative = 0;
	i = 0;
	if (str[i] == '-')
	{
		negative = 1;
		i++;
	}
	if (!ft_isdigit(str[i]))
		return (false);
	while (ft_isdigit(str[i]))
	{
		prev = *out_num;
		*out_num = *out_num * 10 + str[i] - '0';
		if (check_overflow(prev, *out_num) == true)
			return (false);
		i++;
	}
	if (negative)
		*out_num *= -1;
	return (true);
}
