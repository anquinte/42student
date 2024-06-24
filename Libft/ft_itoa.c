/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anquinte <anquinte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 17:41:29 by anquinte          #+#    #+#             */
/*   Updated: 2024/06/16 11:22:41 by anquinte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_num_size(int num)
{
	int	size;

	size = 0;
	if (num < 1)
		size++;
	while (num != '\0')
	{
		num = num / 10;
		size++;
	}
	return (size);
}

static char	*ft_str(int num)
{
	char	*str;

	str = (char *)ft_calloc((num + 1), sizeof(char));
	if (str == NULL)
		return (NULL);
	return (str);
}

static char	*ft_itoa_(int n)
{
	char	*str;
	int		size;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	size = ft_num_size(n);
	str = ft_str(size);
	if (str == NULL)
		return (NULL);
	if (n < 0)
		n *= -1;
	while (size-- > 0)
	{
		str[size] = n % 10 + '0';
		n = n / 10;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	char	*result;

	result = ft_itoa_(n);
	if (result == NULL)
		return (result);
	if (n < 0)
	{
		result[0] = '-';
	}
	return (result);
}
