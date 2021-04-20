/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_stack_sort.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 10:26:21 by clkuznie          #+#    #+#             */
/*   Updated: 2021/04/20 21:35:15 by clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_list
*quick_sort_exit(t_list **wrong_sequence)
{
	ft_lstclear(wrong_sequence, sequence_elem_delete_function);
	return (NULL);
}

// static void
// stack_partition(void)
// {
// 	return ;
// }

static int
quick_sort_recursive_loop(int *stack[4], t_instruction_function instruction_array[256],
	t_list *quick_instruction_sequence, int partition_len)
{
	t_list	*next_instruction;
	long	instruction_index;

(void)stack; (void)instruction_array; (void)quick_instruction_sequence; (void)partition_len; (void)next_instruction; (void)instruction_index;
	// instruction_index = 0;
	// next_instruction = ft_lstnew((void *)instruction_index);
	// if (!instruction_index || !next_instruction)
	// 	return (quick_sort_exit(&quick_instruction_sequence));
	// (*instruction_array[instruction_index])(stack);
	// quick_instruction_sequence->content++;
	// ft_lstadd_back(&quick_instruction_sequence, next_instruction);
	// debug_print_stack(stack, "quick_stack_sort", debug_option,
	// 	next_instruction);
	return 1;
}

/*
 *	Because of 42 Norme limitation and the personnal objective to not use
 *	structs in this sort algorithm the sequence will be calculated entirely
 *	even if the number of instructions already exceeds the best calculated
 *	sequence length.
 *	Easily added where instructions are applied in a similar maner as did in
 *	the custom bubble_sort algorithm in this project.
*/
t_list
*quick_stack_sort(int *stack[4], t_instruction_function instruction_array[256],
	t_list *best_instruction_sequence, int debug_option)
{
	t_list	*quick_instruction_sequence;

	(void)best_instruction_sequence;
	stack_reset(stack);
	quick_instruction_sequence = ft_lstnew((void *)0);
	if (!quick_instruction_sequence)
		return (NULL);
	debug_print_stack(stack, "quick_stack_sort", debug_option, NULL);
	if (!stack_is_sorted(stack[0]))
	{
		if (quick_sort_recursive_loop(stack, instruction_array,
			quick_instruction_sequence, stack[0][0]) ||
			(long)best_instruction_sequence->content
			< (long)quick_instruction_sequence->content)
			return (quick_sort_exit(&quick_instruction_sequence));
	}
	return (quick_instruction_sequence);
}
