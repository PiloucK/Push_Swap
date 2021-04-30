/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sequence.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 19:58:59 by clkuznie          #+#    #+#             */
/*   Updated: 2021/04/30 20:01:20 by clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list		*
	quick_sequence(
	t_quick_sort_loop_params *params,
	size_t partition_len,
	int current_stack_index,
	size_t last_partition_len)
{
	t_list	*best_instructions;
	int		*best_sequence;

	if (!params->quick_instruction_sequence)
		return (NULL);
	if (partition_len > 3)
		best_instructions = top_stack_sort(params,
			partition_len, current_stack_index);
	else
	{
		if (partition_len == 2)
			best_sequence = quick_sort_two(params->stack,
				current_stack_index);
		else
			best_sequence = quick_sort_three(params->stack,
				current_stack_index, last_partition_len);
		best_instructions = sequence_convert(params, best_sequence);
	}
	return (best_instructions);
}
