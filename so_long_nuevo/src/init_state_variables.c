/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_state_variables.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anquinte <anquinte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 15:05:41 by anquinte          #+#    #+#             */
/*   Updated: 2024/10/26 15:43:32 by anquinte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int init_state_variables(t_so_long *m, char *filename)
{
    m->map_size.x = 0;
    m->map_size.y = 0;
    m->collectable_count = 0;
    m->player_position.x = -1;
    m->player_position.y = -1;
    m->exit_position.x = -1;
    m->exit_position.y = -1;
    m->map = NULL;
    m->filename = filename;
    return 0;
}