/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmajor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 11:33:17 by brmajor           #+#    #+#             */
/*   Updated: 2023/03/24 14:37:16 by brmajor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check(char chr, va_list arg)
{
	if (chr == 'c')
		return (putcharf(va_arg(arg, int)));
	else if (chr == 's')
		return (putstrf(va_arg(arg, char *)));
	else if (chr == 'p')
		return (putptrf(va_arg(arg, unsigned long long)));
	else if (chr == 'd' || chr == 'i')
		return (putnbrf(va_arg(arg, int)));
	else if (chr == 'u')
		return (putdecf(va_arg(arg, unsigned int)));
	else if (chr == 'x' || chr == 'X')
		return (puthexf(va_arg(arg, unsigned int), chr));
	else if (chr == '\n')
		return (putstrf("%\n"));
	else if (chr == '%')
		return (putcharf('%'));
	else
		return (-1);
}

int	ft_printf(const char *input, ...)
{
	int		len;
	int		i;
	va_list	arg;

	va_start(arg, input);
	len = 0;
	i = 0;
	while (input[i])
	{
		if (input[i] == '%' && ft_strchr_p("cspdiuxX%\n", input[i + 1]) == 1)
			len += check(input[++i], arg);
		else if (input [i] == '%')
			return (-1);
		else
			len += putcharf(input[i]);
		i++;
	}
	va_end(arg);
	return (len);
}
