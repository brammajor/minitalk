/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdevries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 15:24:40 by wdevries          #+#    #+#             */
/*   Updated: 2023/07/03 18:04:25 by brmajor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static int	ft_read(int fd, char **line_parse)
{
	char	*buffer;
	char	*new_line_parse;
	ssize_t	bytes_read;

	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (-1);
	bytes_read = 1;
	while (!ft_gstrchr(*line_parse, '\n') && bytes_read)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(buffer);
			return (-1);
		}
		buffer[bytes_read] = '\0';
		new_line_parse = ft_gstrjoin(*line_parse, buffer);
		free(*line_parse);
		*line_parse = new_line_parse;
	}
	free(buffer);
	return (0);
}

static char	*ft_extract(char **line_parse)
{
	char	*nl_position;
	char	*line_return;
	char	*new_line_parse;

	nl_position = ft_gstrchr(*line_parse, '\n');
	if (nl_position)
	{
		new_line_parse = ft_gstrdup(nl_position + 1);
		*(nl_position + 1) = '\0';
		line_return = ft_gstrdup(*line_parse);
		free_line(line_parse);
		*line_parse = new_line_parse;
	}
	else
	{
		line_return = *line_parse;
		*line_parse = NULL;
	}
	return (line_return);
}

char	*get_next_line(int fd)
{
	static char	*line_parse[OPEN_MAX];
	char		*line_return;

	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE < 1)
		return (NULL);
	if (ft_read(fd, &line_parse[fd]) == -1)
		return (free_line(&line_parse[fd]));
	if (line_parse[fd] && *line_parse[fd] == 0)
		return (free_line(&line_parse[fd]));
	line_return = ft_extract(&line_parse[fd]);
	return (line_return);
}
