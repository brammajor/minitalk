/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmajor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 14:18:58 by brmajor           #+#    #+#             */
/*   Updated: 2023/02/06 15:22:20 by brmajor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static char	*ifpos(int nb, char *str, int len)
{
	while (nb > 0)
	{
		str[len--] = nb % 10 + '0';
		nb = nb / 10;
	}
	return (str);
}

static int	int_len(int n)
{
	int	i;

	i = 1;
	if (n == -2147483648)
		return (11);
	if (n < 0)
	{
		i++;
		n = -n;
	}
	while (n >= 10)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;
	int		nb;

	nb = n;
	len = int_len(nb);
	str = malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[len--] = '\0';
	if (nb == 0)
		str[len] = '0';
	if (nb < 0)
	{
		str[0] = '-';
		if (nb == -2147483648)
		{
			str[len--] = '8';
			nb = -214748364;
		}
		nb = -nb;
	}
	if (nb > 0)
		ifpos(nb, str, len);
	return (str);
}
