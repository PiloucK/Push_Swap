/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_stack_sort.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 10:27:47 by clkuznie          #+#    #+#             */
/*   Updated: 2021/04/20 17:14:27 by clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_list
*bubble_sort_exit(t_list **wrong_sequence)
{
	ft_lstclear(wrong_sequence, sequence_elem_delete_function);
	return (NULL);
}

static long
bubble_sort_next_instruction(int *stack[3])
{
	if (stack_is_sorted(stack[0]) && stack[0][1])
		return (PA);
	if (stack[0][1] > stack[0][2]
		&& !(util_is_stack_biggest(stack, stack[0][1], 0)
			&& util_is_stack_smallest(stack, stack[0][2], 0)))
		return (SA);
	if (util_is_stack_smallest(stack, stack[0][1], 0))
		return (PB);
	return (RA);
}

t_list
*bubble_stack_sort(int *stack[3], t_instruction_function instruction_array[256],
	t_list *best_instruction_sequence, int debug_option)
{
	t_list	*bubble_instruction_sequence;
	t_list	*next_instruction;
	long	instruction_index;

	stack_reset(stack);
	bubble_instruction_sequence = ft_lstnew((void *)0);
	if (!bubble_instruction_sequence)
		return (NULL);
	debug_print_stack(stack, "bubble_stack_sort", debug_option, NULL);
	while(!stack_is_sorted(stack[0]) || stack[1][0])
	{
		instruction_index = bubble_sort_next_instruction(stack);
		next_instruction = ft_lstnew((void *)instruction_index);
		if (!instruction_index || !next_instruction ||
			bubble_instruction_sequence->content
			== best_instruction_sequence->content)
			return (bubble_sort_exit(&bubble_instruction_sequence));
		(*instruction_array[instruction_index])(stack);
		bubble_instruction_sequence->content++;
		ft_lstadd_back(&bubble_instruction_sequence, next_instruction);
		debug_print_stack(stack, "bubble_stack_sort", debug_option,
			next_instruction);
	}
	return (bubble_instruction_sequence);
}
