/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printuns.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anquinte <anquinte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 15:28:38 by anquinte          #+#    #+#             */
/*   Updated: 2024/06/20 12:26:14 by anquinte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_printuns(unsigned int n)
{
    int charprint;

    charprint = 0;
    if(n > 9)
        charprint += ft_printuns(n / 10);
    charprint += ft_printchar(n % 10 + '0');
    return (charprint);
}