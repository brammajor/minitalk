/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmajor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 16:51:20 by brmajor           #+#    #+#             */
/*   Updated: 2023/01/16 10:26:20 by brmajor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*u;
	unsigned char	*v;

	i = 0;
	u = (unsigned char *)dest;
	v = (unsigned char *)src;
	if (!n || dest == src)
		return (dest);
	while (i < n)
	{
		u[i] = v[i];
		i++;
	}
	return (dest);
}
