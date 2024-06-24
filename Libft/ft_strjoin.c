/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anquinte <anquinte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 13:12:50 by anquinte          #+#    #+#             */
/*   Updated: 2024/06/14 14:43:37 by anquinte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	int		k;
	char	*s;

	i = 0;
	j = 0;
	k = 0;
	s = (char *)ft_calloc((ft_strlen(s1) + ft_strlen(s2) + 1), sizeof(char));
	if (s == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		s[k] = s1[i];
		k++;
		i++;
	}
	while (s2[j] != '\0')
	{
		s[k] = s2[j];
		k++;
		j++;
	}
	return (s);
}
