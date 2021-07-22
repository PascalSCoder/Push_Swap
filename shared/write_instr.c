/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   write_instr.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/06 15:41:32 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/06/06 16:45:19 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../includes/shared.h"

static char	*get_base(t_instrkey key)
{
	if (key == push)
		return "p";
	if (key == swap)
		return "s";
	if (key == rotate)
		return "r";
	return "rr";
}

/*
	Supply one of the possible keys: p, s, r or rr and supply t_stack_id.
	Writes the instruction to standard output.
*/
void	write_instr(t_instrkey key, t_stackid id)
{
	char	*base;
	char	str[3];
	int		i;

	base = get_base(key);
	i = 0;
	while (base[i])
	{
		str[i] = base[i];
		i++;
	}
	if (id == stack_ab)
		str[i] = str[i - 1];
	else
		str[i] = id + 'a';
	write(1, str, i + 1);
	write(1, "\n", 1);
}
