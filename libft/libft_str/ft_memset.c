/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmajor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 15:31:25 by brmajor           #+#    #+#             */
/*   Updated: 2023/01/16 10:15:46 by brmajor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*u;

	i = 0;
	u = (unsigned char *)s;
	while (i < n)
	{
		u[i] = (unsigned char)c;
		i++;
	}
	return (s);
}
