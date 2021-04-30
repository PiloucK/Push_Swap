/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_push_cleanup.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 17:53:51 by clkuznie          #+#    #+#             */
/*   Updated: 2021/04/30 20:02:46 by clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void
	quick_push_cleanup(
	t_list *quick_sequence)
{
	t_list	*potential_useless_push;
	t_list	*sequence_first;
	int		push_count;

	if (!quick_sequence)
		return ;
	sequence_first = quick_sequence;
	quick_sequence = quick_sequence->next;
	while (quick_sequence)
	{
		push_count = 0;
		potential_useless_push = NULL;
		if ((size_t)quick_sequence->content == PB && ++push_count)
			potential_useless_push = quick_sequence;
		quick_sequence = quick_sequence->next;
		while (quick_sequence
			&& (((size_t)quick_sequence->content == PB && ++push_count)
				|| ((size_t)quick_sequence->content == PA && push_count--)))
			quick_sequence = quick_sequence->next;
		quick_delete_useless_push(sequence_first, potential_useless_push,
			quick_sequence, push_count);
		while (quick_sequence && (size_t)quick_sequence->content != PB)
			quick_sequence = quick_sequence->next;
	}
}
