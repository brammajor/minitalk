/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmajor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 14:02:19 by brmajor           #+#    #+#             */
/*   Updated: 2023/01/25 14:44:29 by brmajor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t			i;
	size_t			dest_len;
	size_t			src_len;

	dest_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	if (n == 0)
		return (src_len);
	if (!dest || !src)
		return (0);
	i = 0;
	if (dest_len > n)
		return (src_len + n);
	while ((i + dest_len + 1) < n && src[i])
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	dest[dest_len + i] = '\0';
	return (dest_len + src_len);
}
