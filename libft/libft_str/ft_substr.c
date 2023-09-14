/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmajor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 15:37:12 by brmajor           #+#    #+#             */
/*   Updated: 2023/02/06 14:30:37 by brmajor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char		*u;
	size_t		i;
	size_t		slen;

	i = 0;
	slen = (unsigned int)ft_strlen(s);
	if (!s)
		return (NULL);
	if (start >= slen)
		return (ft_strdup(""));
	if (len > slen - start)
		len = slen - start;
	u = (char *)malloc(sizeof(char) * (len + 1));
	if (!u)
		return (NULL);
	while (i < len)
		u[i++] = s[start++];
	u[i] = '\0';
	return (u);
}
