/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmajor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 17:29:41 by brmajor           #+#    #+#             */
/*   Updated: 2023/01/18 11:54:05 by brmajor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	char	*u;
	int		i;
	int		len;

	i = 0;
	if (!s || !f)
		return (NULL);
	len = ft_strlen(s);
	u = malloc((len + 1) * sizeof(char));
	if (!u)
		return (NULL);
	while (i < len)
	{
		u[i] = (*f)(i, s[i]);
		i++;
	}
	u[i] = '\0';
	return (u);
}
