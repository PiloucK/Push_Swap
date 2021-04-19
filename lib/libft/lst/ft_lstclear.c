/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/19 00:39:22 by jmaydew           #+#    #+#             */
/*   Updated: 2021/04/19 16:13:29 by clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list *store;

	if (lst != NULL)
	{
		if (*lst)
		{
			while ((*lst)->next)
			{
				store = *lst;
				*lst = (*lst)->next;
				del(store->content);
				free(store);
			}
			del((*lst)->content);
			free(*lst);
		}
		*lst = NULL;
	}
}
