/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sequence_elem_functions.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 19:53:07 by clkuznie          #+#    #+#             */
/*   Updated: 2021/04/21 11:06:20 by clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void
sequence_elem_print_function(void *elem_content)
{
	if ((long)elem_content == PA)
		ft_printf("pa\n");
	else if ((long)elem_content == PB)
		ft_printf("pb\n");
	else if ((long)elem_content == RA)
		ft_printf("ra\n");
	else if ((long)elem_content == RB)
		ft_printf("rb\n");
	else if ((long)elem_content == RR)
		ft_printf("rr\n");
	else if ((long)elem_content == RRA)
		ft_printf("rra\n");
	else if ((long)elem_content == RRB)
		ft_printf("rrb\n");
	else if ((long)elem_content == RR)
		ft_printf("rrr\n");
	else if ((long)elem_content == SA)
		ft_printf("sa\n");
	else if ((long)elem_content == SB)
		ft_printf("sb\n");
	else if ((long)elem_content == SS)
		ft_printf("ss\n");
}

void
sequence_elem_delete_function(void *data)
{
	(void)data;
}
