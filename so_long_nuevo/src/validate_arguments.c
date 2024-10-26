/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_arguments.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anquinte <anquinte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 15:18:12 by anquinte          #+#    #+#             */
/*   Updated: 2024/10/26 15:18:15 by anquinte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "so_long.h"

int validate_arguments(int argc, char **argv)
{
    if(argc != 2 && !argv[1][0])
    {
        return 1;
    }
    return 0;
}