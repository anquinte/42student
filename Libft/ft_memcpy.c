/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anquinte <anquinte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 15:28:56 by anquinte          #+#    #+#             */
/*   Updated: 2024/05/02 15:34:26 by anquinte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*source;
	unsigned char	*desti;

	i = 0;
	source = (unsigned char *) src;
	desti = (unsigned char *) dst;
	if (src == NULL && dst == NULL)
		return (NULL);
	while (i < n)
	{
		desti[i] = source[i];
		i++;
	}
	return (dst);
}
