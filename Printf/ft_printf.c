/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anquinte <anquinte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 11:41:18 by anquinte          #+#    #+#             */
/*   Updated: 2024/06/26 11:12:11 by anquinte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_printchecker(va_list va, char word)
{
	if (word == 'c')
		return (ft_printchar(va_arg(va, int)));
	else if (word == 's')
		return (ft_printstr(va_arg(va, char *)));
	else if (word == 'd' || word == 'i')
		return (ft_printnbr(va_arg(va, int)));
	else if (word == 'u')
		return (ft_printuns(va_arg(va, unsigned int)));
	else if (word == 'x' || word == 'X')
		return (ft_printhex(va_arg(va, unsigned int), word));
	else if (word == 'p')
		return (ft_printpointer(va_arg(va, void *)));
	else if (word == '%')
		return (ft_printchar('%'));
	return (0);
}

int	ft_printf(char const *str, ...)
{
	size_t	i;
	int		charprint;
	va_list	va;

	i = 0;
	charprint = 0;
	va_start(va, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			charprint += ft_printchecker(va, str[i]);
		}
		else if (str[i] != '%')
			charprint += ft_printchar(str[i]);
		i++;
	}
	va_end(va);
	return (charprint);
}
