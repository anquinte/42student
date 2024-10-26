/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anquinte <anquinte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 15:21:22 by anquinte          #+#    #+#             */
/*   Updated: 2024/10/26 15:48:27 by anquinte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/so_long.h"
//#include "../MLX42/MLX42.h"
#include <stdio.h>

int printmap(t_so_long *m)
{
    int i;

    i = 0;
    while (i < m->map_size.x)
    {
        printf("%s\n", m->map[i]);
        i++;
    }
}

int check_map_integrity(t_so_long *s)
{
    return (0);
    /*if (check_map_closed(s))
        return (1);
    if (check_map_one_player(s))
        return (1);
    if (check_map_collectable(s))
        return (1);
    if (check_map_exit(s))
        return (1);
    if (check_map_rectangle(s))
        return (1);
    if (check_map_connectivity(s))
        return (1);
    if (check_map_file_extension(s))
        return (1);
    if (check_map_invalid_character(s))
        return (1);*/
    
}

int find_map_objects(t_so_long *state)
{
    return (0);
    /*if (find_collectable_count(state))
        return (1);
    if (find_exit_position(state))
        return (1);
    if (find_player_position(state))
        return (1);*/
    
}

int init_game_state(t_so_long *state, char *filename)
{
    if (init_state_variables(state, filename))
        return (1);
    if (read_map(state))
        return (1);
    if (check_map_integrity(state))
        return (1);
    if (find_map_objects(state))
        return (1);
    return (0);
}

int main(int argc, char **argv)
{
    t_so_long state;

    if (validate_arguments(argc, argv))
        return (1);
    if (init_game_state(&state, argv[1]))
    {
        delete_state(&state);
        return (1);
    }
    printmap(&state);
    
   //mlx_t *mlx = mlx_init(600, 800, "so_long_nuevo", true);
   // if(!mlx)
     //   return 1;
    
   // mlx_loop(mlx);
   // mlx_terminate(mlx);
    delete_state(&state);
    return (0);
}
