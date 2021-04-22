/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extraction_stack_sort.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 15:12:28 by clkuznie          #+#    #+#             */
/*   Updated: 2021/04/22 15:12:52 by clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_list
*extraction_sort_exit(t_list **wrong_sequence)
{
	ft_lstclear(wrong_sequence, sequence_elem_delete_function);
	return (NULL);
}

static long
extraction_sort_next_instruction(int *stack[4])
{
	if (stack_is_sorted(stack[0]) && stack[1][0])
		return (PA);
	// if (stack[0][1] > stack[0][2]
	// 	&& !(util_is_stack_biggest(stack, stack[0][1], 0)
	// 		&& util_is_stack_smallest(stack, stack[0][2], 0)))
	// 	return (SA);
	if (util_is_stack_smallest(stack, stack[0][1], 0))
		return (PB);
	return (RA);
}

t_list
*extraction_stack_sort(int *stack[4], t_instruction_function instruction_array[256],
	t_list *best_instruction_sequence, int debug_option)
{
	t_list	*extraction_instruction_sequence;
	t_list	*next_instruction;
	long	instruction_index;

	stack_reset(stack);
	extraction_instruction_sequence = ft_lstnew((void *)0);
	if (!extraction_instruction_sequence)
		return (NULL);
	debug_print_stack(stack, "extraction_stack_sort", debug_option, NULL);
	while(!stack_is_sorted(stack[0]) || stack[1][0])
	{
		instruction_index = extraction_sort_next_instruction(stack);
		next_instruction = ft_lstnew((void *)instruction_index);
		if (!instruction_index || !next_instruction ||
			extraction_instruction_sequence->content
			== best_instruction_sequence->content)
			return (extraction_sort_exit(&extraction_instruction_sequence));
		(*instruction_array[instruction_index])(stack);
		extraction_instruction_sequence->content++;
		ft_lstadd_back(&extraction_instruction_sequence, next_instruction);
		debug_print_stack(stack, "extraction_stack_sort", debug_option,
			next_instruction);
	}
	return (extraction_instruction_sequence);
}
