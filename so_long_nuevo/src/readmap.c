/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anquinte <anquinte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 15:20:54 by anquinte          #+#    #+#             */
/*   Updated: 2024/10/26 15:43:54 by anquinte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "get_next_line.h"
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

int read_map(t_so_long *m)
{
    int fd;
    char *line;
    char *mapstr;
    char *tmp;

    fd = open(m->filename, O_RDONLY);
    if (fd < 0)
    {
        perror("Error opening file");
        return (1);
    }
        
    line = (char *)1;
    mapstr = ft_strdup("");
    if (!mapstr)
    {
        write(2, "Memory allocation error\n", 24);
        close(fd);
        return 1;
    }
        
    m->map_size.y = 0;
    while(line)
    {
        tmp = mapstr;
        line = get_next_line(fd);
        if(line)
        {
            m->map_size.y++;
            //if(m->map_size.y == 1)
            m->map_size.x = ft_strlen(line);
            if (line[0] == '\0')
                mapstr = ft_strjoin(mapstr, "\n");
            else
                mapstr = ft_strjoin(mapstr, line);
            if(!mapstr)
            {
                write(2, "Memory allocation error in ft_strjoin\n", 38);
                free(line);
                free(tmp);
                close(fd);
                return 1;
            }
            free(line);
            free(tmp);
        }
    }
    m->map = ft_split(mapstr, '\n');
    free(mapstr);
    close(fd);
    if (!m->map)
    {
        write(2, "Error splitting map\n", 20);
        return 1;
    }
        
    return (0);
}

/*int main(int argc, char **argv)
{
    int i;

    i = 0;
    if (argc != 2)
    {
        write(2, "No", 2);
        return 1;
    }
    t_so_long state;
    init_state_variables(&state, argv[1]);
    state.filename = argv[1];
    //read_map(&state);
   if(read_map(&state) != 0)
    {
        write(2, "Error\n", 6);
        return 1;
    }
   while(i < state.map_size.y)
    {
        if (state.map[i])
            printf("%s\n", state.map[i]);
        i++;
    }
  
     //printf("%s\n", state.map[0]);
    //printf("%s\n", state.map[1]);
    //printf("%s\n", state.map[2]);
    //printf("%s\n", state.map[3]);
    //printf("%s\n", state.map[4]);
    delete_state(&state);
    return 0;
}*/