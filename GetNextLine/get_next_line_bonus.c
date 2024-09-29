/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anquinte <anquinte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 17:23:46 by anquinte          #+#    #+#             */
/*   Updated: 2024/09/29 19:16:25 by anquinte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
	if (!left_buffer)
		free(left_buffer);
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
		else if (bytes_read == 0)
			break ;
		buffer[bytes_read] = '\0';
		if (!left_buffer)
			left_buffer = ft_strdup("");
		tmp = left_buffer;
		left_buffer = ft_strjoin(tmp, buffer);
		free(tmp);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (left_buffer);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	char		*line;
	static char	*left_line[__FD_SETSIZE];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	line = read_from_file(fd, buffer, left_line[fd]);
	free(buffer);
	if (!line)
		return (NULL);
	left_line[fd] = extract_line(line);
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
/*
int main() {
    int     fd;
    int     fd2;
    int     fd3;
    char    *next_line;
    int     count;

    count = 0;
    fd = open("prueba1.txt", O_RDONLY);
    fd2 = open("prueba2.txt", O_RDONLY);
    fd3 = open("prueba3.txt", O_RDONLY);
    if (fd == -1 || fd2 == -1 || fd3 == -1) 
    {
        perror("Error al abrir archivo");
        return 1;
    }

    while ((next_line = get_next_line(fd)) != NULL) {
        count++;
        printf("[%d]: %s\n", count, next_line);
        free(next_line);
    }

    while ((next_line = get_next_line(fd2)) != NULL) {
        count++;
        printf("[%d]: %s\n", count, next_line);
        free(next_line);
    }

    while ((next_line = get_next_line(fd3)) != NULL) {
        count++;
        printf("[%d]: %s\n", count, next_line);
        free(next_line);
    }

    if (close(fd) == -1) {
        perror("Error al cerrar archivo");
        return 1;
    }

    if (close(fd2) == -1) {
        perror("Error al cerrar archivo");
        return 1;
    }

    if (close(fd3) == -1) {
        perror("Error al cerrar archivo");
        return 1;
    }
    return 0;
}*/