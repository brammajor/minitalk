/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdevries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 15:25:06 by wdevries          #+#    #+#             */
/*   Updated: 2023/07/27 16:30:07 by brmajor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_gstrlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*free_line(char **line)
{
	if (*line)
	{
		free(*line);
		*line = NULL;
	}
	return (NULL);
}

char	*ft_gstrchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	return (0);
}

char	*ft_gstrdup(const char *s)
{
	int		len;
	char	*p;
	char	*p_start;

	len = ft_gstrlen(s);
	p = (char *)malloc((len + 1) * sizeof(char));
	if (!p)
		return (NULL);
	p_start = p;
	while (s && *s)
		*p++ = *s++;
	*p = '\0';
	return (p_start);
}

char	*ft_gstrjoin(char const *line_parse, char const *buffer)
{
	size_t	len;
	char	*new_s;
	char	*new_s_start;

	if (!line_parse && !buffer)
		return (NULL);
	len = ft_gstrlen(line_parse) + ft_gstrlen(buffer);
	new_s = (char *)malloc((len + 1) * sizeof(char));
	if (!new_s)
		return (NULL);
	new_s_start = new_s;
	while (line_parse && *line_parse)
		*new_s++ = *line_parse++;
	while (buffer && *buffer)
		*new_s++ = *buffer++;
	*new_s = '\0';
	return (new_s_start);
}
