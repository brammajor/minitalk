/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putstrf.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmajor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 16:39:58 by brmajor           #+#    #+#             */
/*   Updated: 2023/02/08 14:52:17 by brmajor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	putstrf(char *arg)
{
	int	len;

	if (!arg)
		return (putstrf("(null)"));
	len = 0;
	while (arg[len])
	{
		write(1, &arg[len], 1);
		len++;
	}
	return (ft_strlen(arg));
}
