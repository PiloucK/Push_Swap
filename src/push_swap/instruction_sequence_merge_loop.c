/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_sequence_merge_loop.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 17:42:57 by clkuznie          #+#    #+#             */
/*   Updated: 2021/04/30 17:43:10 by clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void
instruction_sequence_merge_loop(t_list *longer_subsequence, t_list **shorter_subsequence)
{
	size_t	best_instruction_index;
	t_list	*trash_instruction;

	while (longer_subsequence && *shorter_subsequence)
	{
		best_instruction_index = (size_t)(longer_subsequence)->content
			+ (size_t)(*shorter_subsequence)->content;
		if (best_instruction_index == RR || best_instruction_index == RRR
			|| best_instruction_index == SS)
		{
			(longer_subsequence)->content = (void *)best_instruction_index;
			(longer_subsequence) = (longer_subsequence)->next;
			trash_instruction = (*shorter_subsequence);
			(*shorter_subsequence) = (*shorter_subsequence)->next;
			free(trash_instruction);
		}
		else
			instruction_merge_insert(&longer_subsequence, shorter_subsequence);
	}
}
