/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anquinte <anquinte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 16:01:33 by anquinte          #+#    #+#             */
/*   Updated: 2024/10/01 14:24:42 by anquinte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*extract_line(char *line)
{
	int		i;
	char	*left_buffer;

	i = 0;
	while (line[i] != '\0' && line[i] != '\n')
		i++;
	if (!line[i] || !line[i + 1])
		return (NULL);
	left_buffer = ft_substr(line, i + 1, ft_strlen(line) - i);
	line[i + 1] = '\0';
	return (left_buffer);
}

static char	*read_from_file(int fd, char	*buffer, char *left_buffer)
{
	char	*tmp;
	ssize_t	bytes_read;

	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (NULL);
		if (bytes_read == 0)
			break ;
		buffer[bytes_read] = '\0';
		if (!left_buffer)
			left_buffer = ft_strdup(buffer);
		else
		{
			tmp = left_buffer;
			left_buffer = ft_strjoin(tmp, buffer);
			free(tmp);
		}
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (left_buffer);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	char		*line;
	static char	*left_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	line = read_from_file(fd, buffer, left_line);
	free(buffer);
	if (!line)
		return (NULL);
	left_line = extract_line(line);
	return (line);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}
