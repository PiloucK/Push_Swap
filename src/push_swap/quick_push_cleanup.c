/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_push_cleanup.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 17:53:51 by clkuznie          #+#    #+#             */
/*   Updated: 2021/04/30 17:53:52 by clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void
quick_push_cleanup(t_list *quick_sort_best_sequence)
{
	t_list	*potential_useless_push;
	t_list	*sequence_first;
	int		push_count;

	if (!quick_sort_best_sequence)
		return ;
	sequence_first = quick_sort_best_sequence;
	quick_sort_best_sequence = quick_sort_best_sequence->next;
	while (quick_sort_best_sequence)
	{
		push_count = 0;
		potential_useless_push = NULL;
		if ((size_t)quick_sort_best_sequence->content == PB && ++push_count)
			potential_useless_push = quick_sort_best_sequence;
		quick_sort_best_sequence = quick_sort_best_sequence->next;
		while (quick_sort_best_sequence
			&& (size_t)quick_sort_best_sequence->content == PB && ++push_count)
			quick_sort_best_sequence = quick_sort_best_sequence->next;
		while (quick_sort_best_sequence
			&& (size_t)quick_sort_best_sequence->content == PA && push_count--)
			quick_sort_best_sequence = quick_sort_best_sequence->next;
		quick_delete_useless_push(sequence_first, potential_useless_push,
			quick_sort_best_sequence, push_count);
		while (quick_sort_best_sequence
			&& (size_t)quick_sort_best_sequence->content != PB)
			quick_sort_best_sequence = quick_sort_best_sequence->next;
	}
}
