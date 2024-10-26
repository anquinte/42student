/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_state.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anquinte <anquinte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 15:20:21 by anquinte          #+#    #+#             */
/*   Updated: 2024/10/26 15:20:25 by anquinte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void delete_state(t_so_long *state)
{
    int i;

    i = 0;
    if(state->map)
    {
        while(i < state->map_size.y)
        {
            free(state->map[i]);
            i++;
        }
        free(state->map);
        state->map = NULL;
    }
    if (state->filename)
    {
        state->filename = NULL;
        free(state->filename);
    }
}