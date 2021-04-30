/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort_partitionning.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 17:46:53 by clkuznie          #+#    #+#             */
/*   Updated: 2021/04/30 21:21:01 by clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t
	quick_sort_partitionning(
	t_quick_sort_loop_params *params,
	int current_stack_index,
	size_t partition_len)
{
	size_t	next_partition_len;
	float	partition_median;

	if (!params->quick_instruction_sequence)
		return (0);
	if (partition_len <= PARTITION_SIZE)
		return (0);
	if ((array_is_ascending(params->stack[current_stack_index] + 1,
			partition_len) && !current_stack_index)
		|| (array_is_descending(params->stack[current_stack_index] + 1,
			partition_len) && current_stack_index))
		return (0);
	partition_median = partition_median_get(params->stack[3],
		array_smallest(&params->stack[current_stack_index][1],
			partition_len), partition_len);
	next_partition_len = partition_len / 2;
	if (!quick_partition_push(params, current_stack_index, partition_median,
		partition_len))
		quick_sort_exit(params);
	return (next_partition_len);
}
