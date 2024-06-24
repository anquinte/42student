/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anquinte <anquinte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 11:58:39 by anquinte          #+#    #+#             */
/*   Updated: 2024/06/20 20:39:45 by anquinte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_printstr(char *s)
{
    size_t i;
    int charprint;

    i = 0;
    charprint = 0;
    if(!s)
        s = "(null)";
    while (s[i])
    {
        write (1, &s[i], 1);
        i++;
        charprint++;
    }
    return (charprint);
}