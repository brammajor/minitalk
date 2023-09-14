/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmajor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 11:46:53 by brmajor           #+#    #+#             */
/*   Updated: 2023/01/26 12:17:01 by brmajor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*u;

	u = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (u[i] == (unsigned char)c)
			return ((void *)(&u[i]));
		i++;
	}
	return (NULL);
}
/*
#include <stdio.h>

int	main()
{
	char	str[] = "Banaan";

	printf("%s", (char *)ft_memchr(str, 'a', sizeof(str)));
}*/
