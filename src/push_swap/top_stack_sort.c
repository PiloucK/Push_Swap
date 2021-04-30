/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   top_stack_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 17:55:50 by clkuznie          #+#    #+#             */
/*   Updated: 2021/04/30 17:55:51 by clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*
top_stack_sort(t_quick_sort_loop_params *params, size_t partition_len, int current_stack_index)
{
	t_list	*top_instruction_sequence;
	t_list	*next_instruction;

	util_stack_copy(params->stack_copy[0], params->stack[0]);
	util_stack_copy(params->stack_copy[1], params->stack[1]);
	util_stack_copy(params->stack_copy[2], params->stack[2]);
	util_stack_copy(params->stack_copy[3], params->stack[3]);
	top_instruction_sequence = ft_lstnew((void *)0);
	while (top_instruction_sequence)
	{
		if (!current_stack_index)
			next_instruction = top_stack_sort_a(params->stack_copy, current_stack_index,
				partition_len, &top_instruction_sequence);
		else
			next_instruction = top_stack_sort_b(params->stack_copy, current_stack_index,
				partition_len, &top_instruction_sequence);
		if (!next_instruction)
			break ;
		((params->instruction_array)[(size_t)next_instruction->content])
			(params->stack_copy);
		top_instruction_sequence->content++;
		ft_lstadd_back(&top_instruction_sequence, next_instruction);
		debug_print_stack(params->stack_copy, "top_stack_sort on copy of the array", params->debug_option,
			next_instruction);
	}
	return (top_instruction_sequence);
}
