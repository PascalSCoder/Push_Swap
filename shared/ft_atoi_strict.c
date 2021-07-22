/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi_strict.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/29 21:57:42 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/04/29 22:40:45 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/shared.h"
#include <stdlib.h>

static char	cmp_int(char *str, int n)
{
	char	*cmp;

	cmp = ft_itoa(n);
	if (!cmp)
		return (false);
	if (ft_strcmp(str, cmp) == 0)
	{
		free(cmp);
		return (true);
	}
	free(cmp);
	return (false);
}

char	ft_atoi_strict(char *str, int *out_num)
{
	char	negative;
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
		*out_num = *out_num * 10 + str[i] - '0';
		i++;
	}
	if (negative)
		*out_num *= -1;
	return (cmp_int(str, *out_num));
}
