/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmajor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 12:08:51 by brmajor           #+#    #+#             */
/*   Updated: 2023/03/24 14:43:17 by brmajor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_intlen(int i)
{
	int	len;

	len = 1;
	if (i < 0)
	{
		len++;
		i = -i;
	}
	while (i >= 10)
	{
		len++;
		i = i / 10;
	}
	return (len);
}

int	ft_hexlen(long long i)
{
	int	len;

	len = 1;
	if (i < 0)
	{
		len++;
		i = -i;
	}
	while (i >= 16)
	{
		len++;
		i = i / 16;
	}
	return (len);
}

int	ft_strchr_p(const char *s, char c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (c == s[i])
			return (1);
		i++;
	}
	return (0);
}
