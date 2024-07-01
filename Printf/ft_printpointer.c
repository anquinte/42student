/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printpointer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anquinte <anquinte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 12:11:33 by anquinte          #+#    #+#             */
/*   Updated: 2024/06/26 15:33:54 by anquinte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printpointer(void *n)
{
	int	charprint;

	charprint = 0;
	if (n == NULL)
		charprint += ft_printstr("(nil)");
	else
	{
		charprint += ft_printstr("0x");
		charprint += ft_printhex((unsigned long long)n, 'x');
	}
	return (charprint);
}
