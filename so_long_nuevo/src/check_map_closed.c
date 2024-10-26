/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_closed.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anquinte <anquinte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 15:19:21 by anquinte          #+#    #+#             */
/*   Updated: 2024/10/26 15:19:23 by anquinte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int check_map_closed(t_so_long *m)
{
    return 0;
    int  i;
    
    i = 0;
    while(i < m->map_size.x)
    {
        if (m->map[0][i] != '1')
            return 1;
        if (m->map[m->map_size.y - 1][i] != '1')
            return 1;
        i++;
    }
    while(i < m->map_size.y)
    {
        if(m->map[i][0] != '1')
            return 1;
        if(m->map[i][m->map_size.x - 1]!= '1')
            return 1;
        i++;
    }
    return (0);
}
int main(int argc, char **argv)
{
    int i = 0;
    t_so_long state;

    // Validación de argumentos
    if (argc != 2)
    {
        write(2, "Usage: ./program_name <map_file>\n", 33);
        return 1;
    }

    // Inicialización de las variables del estado
    if (init_state_variables(&state, argv[1]) != 0)
    {
        write(2, "Error initializing game state\n", 29);
        return 1;
    }

    // Lectura del mapa
    if (read_map(&state) == 0)
    {
        write(2, "Error reading map file\n", 23);
        delete_state(&state);
        return 1;
    }

    // Verificación de si el mapa está cerrado
    if (check_map_closed(&state) == 0)
    {
        write(2, "Warning: Map is not closed by walls\n", 36);
    }
    else
    {
        write(1, "Map is closed by walls\n", 23);
    }

    // Impresión del mapa para verificar
    while (i < state.map_size.y)
    {
        if (state.map[i])
            printf("%s\n", state.map[i]);
        i++;
    }

    // Liberación de memoria
    delete_state(&state);
    return 0;
}