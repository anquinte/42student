/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anquinte <anquinte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 16:01:33 by anquinte          #+#    #+#             */
/*   Updated: 2024/09/26 10:32:25 by anquinte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*set_line(char *line_buffer)
{
	int		i;
	char	*left_buffer;

	i = 0;
	while (line_buffer[i] != '\0' && line_buffer[i] != '\n')
		i++;
	if (!line_buffer[i] || !line_buffer[i + 1])
		return (NULL);
	left_buffer = ft_substr(line_buffer, i + 1, ft_strlen(line_buffer) - i);
	if (!left_buffer)
		free(left_buffer);
	line_buffer[i + 1] = '\0';
	return (left_buffer);
}

static char	*fill_line(int fd, char	*buffer, char *left_buffer)
{
	char	*tmp;
	ssize_t	rd;

	rd = 1;
	while (rd > 0)
	{
		rd = read(fd, buffer, BUFFER_SIZE);
		if (rd == -1)
			return (NULL);
		else if (rd == 0)
			break ;
		buffer[rd] = '\0';
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
	static char	*left_buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	line = fill_line(fd, buffer, left_buffer);
	free(buffer);
	if (!line)
		return (NULL);
	left_buffer = set_line(line);
	return (line);
}

/*int main() {
    int fd;
    char *next_line;
    int count;

    count = 0;
    fd = open("prueba1.txt", O_RDONLY);
    if (fd == -1) {
        perror("Error al abrir archivo");
        return 1;
    }

    while ((next_line = get_next_line(fd)) != NULL) {
        count++;
        printf("[%d]: %s", count, next_line);
        free(next_line);
    }

    if (close(fd) == -1) {
        perror("Error al cerrar archivo");
        return 1;
    }

    return 0;
}
*/
