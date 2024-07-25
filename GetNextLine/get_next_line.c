/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anquinte <anquinte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 16:01:33 by anquinte          #+#    #+#             */
/*   Updated: 2024/07/25 17:21:18 by anquinte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char    *set_line(char *line_buffer)
{
    char    *c;
    ssize_t i;

    i = 0;
    while (line_buffer[i] != '\n' || line_buffer[i] != '\0')
        i++;
    if (!line_buffer[i] || !line_buffer[1])
        return (NULL);
        //xd
    c = ft_substr(line_buffer, i + 1, ft_strlen(line_buffer) - i);
    if (c == NULL)
    {
        free(c);
        c = NULL;
    }
    line_buffer[i + 1] = '\0';
    return (c);
}
static char    *read_line_buffer(int fd, char *c, char *buffer)
{
    char    *tmp;
    char    *sjoin;
    ssize_t rd;

    rd = read(fd, buffer, BUFFER_SIZE);
    while(rd == 0)
    {
        if (rd < 0)
        {
            free(buffer);
            return (NULL);
        }
        if(!tmp)
            tmp = ft_strdup("");
        sjoin = ft_strjoin(tmp, buffer);
        free(tmp);
        if (ft_strchr(sjoin, '\n'))
            break;
    }
    return (sjoin);
}

char    *get_next_line(int fd)
{
    char    *filename;
    ssize_t bytes_size;
    static char    *stash;
    
    if (fd < 0 || BUFFER_SIZE <= 0)
    {
        free(stash);
        free(filename);
        stash = NULL;
        filename = NULL;
        return (NULL);
    }
    
    stash = read_line_buffer(fd, filename, stash);
    if (!stash)
    {
        free(stash);
        return (NULL);
    }
    set_line(stash);
    return (stash);
}

int main()
{
    char *stash;
    int fd = open("prueba.txt", O_RDONLY);
    stash = get_next_line(fd);
    printf("linea: %s\n", stash);
    free(stash);
    return (0);
}
