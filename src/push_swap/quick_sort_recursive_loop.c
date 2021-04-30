/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort_recursive_loop.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 17:56:55 by clkuznie          #+#    #+#             */
/*   Updated: 2021/04/30 20:15:30 by clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*
	quick_sort_recursive_loop(
	t_quick_sort_loop_params *params,
	size_t partition_len,
	size_t last_partition_len)
{
	t_list		*instruction_subsequence;
	static int	current_stack_index;
	size_t		next_partition_len;

	next_partition_len = quick_sort_partitionning(params,
		current_stack_index, partition_len);
	if (params->quick_instruction_sequence && next_partition_len)
	{
		instruction_subsequence = quick_sort_recursive_loop(params,
			partition_len - next_partition_len, partition_len);
		instruction_subsequence = instruction_sequence_merge(
			instruction_subsequence, quick_sort_recursive_loop(params,
			next_partition_len, partition_len));
		quick_apply(params, instruction_subsequence);
		instruction_sequence_concat(params->quick_instruction_sequence,
			instruction_subsequence);
		quick_push_back(params, next_partition_len, current_stack_index);
		current_stack_index = !current_stack_index;
		return (NULL);
	}
	instruction_subsequence = quick_sequence(params,
		partition_len, current_stack_index, last_partition_len);
	current_stack_index = !current_stack_index;
	return (instruction_subsequence);
}
