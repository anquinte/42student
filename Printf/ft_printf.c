/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anquinte <anquinte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 11:41:18 by anquinte          #+#    #+#             */
/*   Updated: 2024/06/22 21:55:35 by anquinte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_printf(char const *str, ...)
{
    size_t  i;
    int charprint;
    va_list va;
    void    *n;

    i = 0;
    charprint = 0;
    va_start(va,str);
    while (str[i])
    {
        if (str[i] == '%')
        {
            if (str[i + 1] == 'c')
               charprint += ft_printchar(va_arg(va,int));
            else if (str[i + 1] == 's')
                charprint += ft_printstr(va_arg(va,char *));
            else if (str[i + 1] == 'd' || str[i + 1] == 'i')
                charprint += ft_printnbr((long)va_arg(va,int));
            else if (str[i + 1] == 'u')
                charprint += ft_printuns(va_arg(va, unsigned int));
            else if (str[i + 1] == 'x' || str[i + 1] == 'X')
                charprint += ft_printhex(va_arg(va, unsigned int), str[i + 1]);
            else if (str[i + 1] == 'p')
            {
                n = va_arg(va, void *);
                if (n == NULL)
                    charprint += ft_printstr("(nil)");
                else
                {
                    charprint += ft_printstr("0x");
                    charprint += ft_printhex((long long unsigned int)n, 'x');
                }
            }
            else if (str[i + 1] == '%')
                charprint += ft_printchar('%');
        i++;  
        }
        else
            charprint += write(1, &str[i], 1);
        i++;    
    }
    va_end(va);
    return (charprint);
}