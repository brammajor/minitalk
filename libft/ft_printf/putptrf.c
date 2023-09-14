/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putptrf.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmajor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 14:59:53 by brmajor           #+#    #+#             */
/*   Updated: 2023/02/08 14:37:52 by brmajor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	puthexlongf(unsigned long long arg, char c)
{
	char	*strlow;
	char	*strupp;
	int		i;

	i = 0;
	strlow = "0123456789abcdef";
	strupp = "0123456789ABCDEF";
	if (arg == 0)
		return (putcharf('0'));
	if (arg >= 16)
	{
		i += puthexlongf(arg / 16, c);
		i += puthexlongf(arg % 16, c);
	}
	if (arg < 16)
	{
		i++;
		if (c == 'x')
			putcharf(strlow[arg]);
		if (c == 'X')
			putcharf(strupp[arg]);
	}
	return (i);
}

int	putptrf(unsigned long long arg)
{
	int	len;

	len = 0;
	if (!arg)
		return (putstrf("(nil)"));
	len += write(1, "0x", 2);
	len += puthexlongf(arg, 'x');
	return (len);
}
