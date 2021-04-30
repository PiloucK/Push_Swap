/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_content_swap.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 17:42:03 by clkuznie          #+#    #+#             */
/*   Updated: 2021/04/30 19:41:28 by clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void
	list_content_swap(
	t_list *elem_a,
	t_list *elem_b)
{
	void	*tmp;

	tmp = elem_a->content;
	elem_a->content = elem_b->content;
	elem_b->content = tmp;
}
