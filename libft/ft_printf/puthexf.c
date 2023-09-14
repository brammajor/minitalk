/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puthexf.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmajor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 12:25:48 by brmajor           #+#    #+#             */
/*   Updated: 2023/02/08 14:21:23 by brmajor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	puthexf(unsigned int arg, char c)
{
	char	*strlow;
	char	*strupp;
	int		len;

	len = ft_hexlen(arg);
	strlow = "0123456789abcdef";
	strupp = "0123456789ABCDEF";
	if (arg == 0)
		return (putcharf('0'));
	if (arg >= 16)
	{
		puthexf(arg / 16, c);
		puthexf(arg % 16, c);
	}
	if (arg < 16)
	{
		if (c == 'x')
			putcharf(strlow[arg]);
		if (c == 'X')
			putcharf(strupp[arg]);
	}
	return (len);
}
