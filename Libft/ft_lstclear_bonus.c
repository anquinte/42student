/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anquinte <anquinte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 14:27:23 by anquinte          #+#    #+#             */
/*   Updated: 2024/06/06 11:14:36 by anquinte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*l;
	t_list	*temp;

	if (lst == NULL || del == NULL)
		return ;
	l = *lst;
	while (l != 0)
	{
		temp = l;
		l = l->next;
		del(temp->content);
		free(temp);
	}
	*lst = NULL;
}
