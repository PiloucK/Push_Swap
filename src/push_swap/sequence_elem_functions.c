/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sequence_elem_functions.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 19:53:07 by clkuznie          #+#    #+#             */
/*   Updated: 2021/04/30 19:46:42 by clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void
	sequence_elem_print_function(
	void *elem_content)
{
	if ((long)elem_content == PA)
		write(1, "pa\n", 3);
	else if ((long)elem_content == PB)
		write(1, "pb\n", 3);
	else if ((long)elem_content == RA)
		write(1, "ra\n", 3);
	else if ((long)elem_content == RB)
		write(1, "rb\n", 3);
	else if ((long)elem_content == RR)
		write(1, "rr\n", 3);
	else if ((long)elem_content == RRA)
		write(1, "rra\n", 4);
	else if ((long)elem_content == RRB)
		write(1, "rrb\n", 4);
	else if ((long)elem_content == RRR)
		write(1, "rrr\n", 4);
	else if ((long)elem_content == SA)
		write(1, "sa\n", 3);
	else if ((long)elem_content == SB)
		write(1, "sb\n", 3);
	else if ((long)elem_content == SS)
		write(1, "ss\n", 3);
}

void
	sequence_elem_debug_print(
	void *elem_content)
{
	if ((long)elem_content == PA)
		write(1, " - pa", 5);
	else if ((long)elem_content == PB)
		write(1, " - pb", 5);
	else if ((long)elem_content == RA)
		write(1, " - ra", 5);
	else if ((long)elem_content == RB)
		write(1, " - rb", 5);
	else if ((long)elem_content == RR)
		write(1, " - rr", 5);
	else if ((long)elem_content == RRA)
		write(1, " - rra", 6);
	else if ((long)elem_content == RRB)
		write(1, " - rrb", 6);
	else if ((long)elem_content == RRR)
		write(1, " - rrr", 6);
	else if ((long)elem_content == SA)
		write(1, " - sa", 5);
	else if ((long)elem_content == SB)
		write(1, " - sb", 5);
	else if ((long)elem_content == SS)
		write(1, " - ss", 5);
}

void
	sequence_elem_delete_function(
	void *data)
{
	(void)data;
}
