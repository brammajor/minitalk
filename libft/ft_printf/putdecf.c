/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putdecf.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmajor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 11:55:20 by brmajor           #+#    #+#             */
/*   Updated: 2023/02/08 14:06:34 by brmajor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	uintlen(unsigned int input)
{
	int	i;

	i = 0;
	while (input)
	{
		input = input / 10;
		i++;
	}
	return (i);
}

int	putdecf(unsigned int arg)
{
	if (arg == 0)
	{
		putcharf('0');
		return (1);
	}
	if (arg >= 10)
	{
		putdecf(arg / 10);
		putdecf(arg % 10);
	}
	else
		putcharf(arg + '0');
	return (uintlen(arg));
}
