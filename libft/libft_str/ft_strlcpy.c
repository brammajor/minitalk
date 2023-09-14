/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmajor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 12:30:21 by brmajor           #+#    #+#             */
/*   Updated: 2023/01/26 15:47:23 by brmajor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t n)
{
	size_t			i;
	size_t			j;

	i = 0;
	j = 0;
	while (src[j])
		j++;
	if (n <= 0)
		return (j);
	while (i < n - 1 && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	if (n < j)
		dest[n - 1] = '\0';
	else if (n != 0)
		dest[i] = '\0';
	return (j);
}
