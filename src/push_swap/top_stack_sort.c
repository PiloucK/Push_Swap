/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   top_stack_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 17:55:50 by clkuznie          #+#    #+#             */
/*   Updated: 2021/04/30 20:57:14 by clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void
	stack_full_duplicate(
	int **destination,
	int **source)
{
	util_stack_copy(destination[0], source[0]);
	util_stack_copy(destination[1], source[1]);
	util_stack_copy(destination[2], source[2]);
	util_stack_copy(destination[3], source[3]);
}

static void
	top_apply_just_for_the_norm(
	t_quick_sort_loop_params *params,
	t_list *next_instruction)
{
	((params->instruction_array)[
		(size_t)next_instruction->content])(params->stack_copy);
	debug_print_stack(
		params->stack_copy,
		"top_stack_sort on copy of the array",
		params->debug_option,
		next_instruction);
}

t_list
	*top_stack_sort(
	t_quick_sort_loop_params *params,
	size_t partition_len,
	int current_stack_index)
{
	t_list	*top_instruction_sequence;
	t_list	*next_instruction;

	stack_full_duplicate(params->stack_copy, params->stack);
	top_instruction_sequence = ft_lstnew((void *)0);
	while (top_instruction_sequence)
	{
		if (!current_stack_index)
			next_instruction = top_stack_sort_a(params->stack_copy,
				current_stack_index,
				partition_len, &top_instruction_sequence);
		else
			next_instruction = top_stack_sort_b(params->stack_copy,
				current_stack_index,
				partition_len, &top_instruction_sequence);
		if (!next_instruction)
			break ;
		top_apply_just_for_the_norm(params, next_instruction);
		ft_lstadd_back(&top_instruction_sequence, next_instruction);
		top_instruction_sequence->content++;
	}
	return (top_instruction_sequence);
}
