/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isascii.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pascal <pascal@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/30 11:47:46 by pascal        #+#    #+#                 */
/*   Updated: 2021/01/07 20:46:38 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	else
		return (0);
}
