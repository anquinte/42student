/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anquinte <anquinte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 16:22:35 by anquinte          #+#    #+#             */
/*   Updated: 2024/06/22 17:58:53 by anquinte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_printhex(unsigned long long n, char c)
{
	unsigned long long		charprint;
	char					*hexmin;
	char					*hexmay;

    charprint = 0;
	hexmin = "0123456789abcdef";
	hexmay = "0123456789ABCDEF";
    if (n >= 16)
		charprint+= ft_printhex(n / 16, c);
	if (c == 'x')
		charprint += ft_printchar(hexmin[n % 16]);
	else if (c == 'X')
		charprint += ft_printchar(hexmay[n % 16]);
    return (charprint);
}