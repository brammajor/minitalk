/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnbrf.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmajor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 11:37:43 by brmajor           #+#    #+#             */
/*   Updated: 2023/02/08 11:56:38 by brmajor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	putnbrf(int arg)
{
	int	i;

	i = ft_intlen(arg);
	if (arg < 0)
	{
		if (arg == -2147483648)
		{
			return (write(1, "-2147483648", 11));
		}
		else
		{
			putcharf('-');
			arg = -arg;
		}
	}
	if (arg >= 10)
	{
		putnbrf(arg / 10);
		putnbrf(arg % 10);
	}
	else
		putcharf(arg + '0');
	return (i);
}
