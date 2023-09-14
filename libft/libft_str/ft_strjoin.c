/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmajor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 16:02:29 by brmajor           #+#    #+#             */
/*   Updated: 2023/01/26 12:19:27 by brmajor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	strlength(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char		*u;
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	if (!s1)
		return (NULL);
	u = malloc(strlength(s1) + strlength(s2) + 1);
	if (!u)
		return (NULL);
	while (s1[i])
	{
		u[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		u[i] = s2[j];
		i++;
		j++;
	}
	u[i] = '\0';
	return (u);
}
