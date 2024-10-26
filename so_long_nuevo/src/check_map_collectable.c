/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_collectable.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anquinte <anquinte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 15:17:38 by anquinte          #+#    #+#             */
/*   Updated: 2024/10/26 15:17:46 by anquinte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int check_map_collectable(t_so_long *m)
{
    int collectable_count;
    int i;
    int j;

    collectable_count = 0;
    i = 0;
    j = 0;
    while(i < m->map_size.x)
    {
        while(j < m->map_size.y)
        {
            if(m->map[i][j] == 'C')
                collectable_count++;
        }
    }
    m->collectable_count = collectable_count;
    if (collectable_count == 0)
        return 1;
    return 0;
}