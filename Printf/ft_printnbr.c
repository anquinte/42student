/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anquinte <anquinte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 12:08:15 by anquinte          #+#    #+#             */
/*   Updated: 2024/06/30 15:59:58 by anquinte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printnbr(long int n)
{
	int	charprint;

	charprint = 0;
	if (n == -214783648)
	{
		charprint += ft_printchar('-');
		charprint += ft_printchar('2');
		charprint += ft_printnbr(147483648);
	}
	else if (n < 0)
	{
		charprint += ft_printchar('-');
		charprint += ft_printnbr(-n);
	}
	else if (n > 9)
	{
		charprint += ft_printnbr(n / 10);
		charprint += ft_printnbr(n % 10);
	}
	else
		charprint += ft_printchar(n + '0');
	return (charprint);
}
