/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_rectangle.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anquinte <anquinte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 22:00:11 by anquinte          #+#    #+#             */
/*   Updated: 2024/10/26 15:16:12 by anquinte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int check_map_rectangle(t_so_long *m)
{
    int num_cols;
    int i;

    num_cols = ft_strlen(m->map[0]);
    i = 0;
    while (i < m->map_size.x)
    {
        if (ft_strlen(m->map[i]) != num_cols)
            return 1;
        i++;
    }
    return 0;
}