/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anquinte <anquinte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 11:37:07 by anquinte          #+#    #+#             */
/*   Updated: 2024/06/22 21:54:34 by anquinte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>
#include <unistd.h>

int ft_print_pointer(void *n);
int ft_printf(char const *, ...);
int ft_printchar(char c);
int ft_printnbr(long int n);
int ft_printstr(char *s);
int ft_printuns(unsigned int n);
int ft_printhex(unsigned long long n, char c);

#endif