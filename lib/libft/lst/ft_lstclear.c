/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 17:44:53 by clkuznie          #+#    #+#             */
/*   Updated: 2021/04/20 17:45:00 by clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
