/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_empty_line.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anquinte <anquinte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 15:20:00 by anquinte          #+#    #+#             */
/*   Updated: 2024/10/26 15:20:02 by anquinte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int check_map_empty_line(t_so_long *m)
{
    int i;
	int state;

    i = 0;
	state = 0;
	
    while (i < m->map_size.x)
    {
		if (m->map[i][0] != '\n' && state == 0)
			state = 1;
		else if(m->map[i][0] == '\n' && state == 1)
			state = 2;
		else if (m->map[i][0] != '\n' && state == 2)
		{
			write(2, "Error", 5);
			return 1;
		}
		i++;
    }
    return 0;
}
int main(int argc, char **argv)
{
	t_so_long state;
	if (argc != 2)
		return 1;
	init_game_state(&state, argv[1]);
	
}