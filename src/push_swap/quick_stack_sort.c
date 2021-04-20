/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_stack_sort.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 10:26:21 by clkuznie          #+#    #+#             */
/*   Updated: 2021/04/20 18:17:33 by clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_list
*quick_sort_exit(t_list **wrong_sequence, int *sorted_stack)
{
	ft_lstclear(wrong_sequence, sequence_elem_delete_function);
	free(sorted_stack);
	return (NULL);
}

static void
stack_partition(void)
{
	return ;
}

static int
quick_sort_recursive_loop(int *stack[3], t_instruction_function instruction_array[256],
	t_list *quick_instruction_sequence, int partition_len)
{
	t_list	*next_instruction;
	long	instruction_index;

	// instruction_index = 0;
	next_instruction = ft_lstnew((void *)instruction_index);
	if (!instruction_index || !next_instruction ||
		quick_instruction_sequence->content
		== best_instruction_sequence->content)
		return (quick_sort_exit(&quick_instruction_sequence, sorted_stack));
	// (*instruction_array[instruction_index])(stack);
	// quick_instruction_sequence->content++;
	// ft_lstadd_back(&quick_instruction_sequence, next_instruction);
	// debug_print_stack(stack, "quick_stack_sort", debug_option,
	// 	next_instruction);
	return 0;
}

t_list
*quick_stack_sort(int *stack[3], t_instruction_function instruction_array[256],
	t_list *best_instruction_sequence, int debug_option)
{
	t_list	*quick_instruction_sequence;
	int		*sorted_stack;

	sorted_stack = malloc(sizeof(*sorted_stack) * stack[2][0] + 1);
	if (!sorted_stack)
		return (NULL);
	util_stack_copy(sorted_stack, stack[0]);
	stack_reset(stack);
	quick_instruction_sequence = ft_lstnew((void *)0);
	if (!quick_instruction_sequence)
		return (NULL);
	debug_print_stack(stack, "quick_stack_sort", debug_option, NULL);
	if (!stack_is_sorted(stack[0]))
	{
		if (quick_sort_recursive_loop())
			return (quick_sort_exit(&quick_instruction_sequence, sorted_stack));
	
	}free(sorted_stack);
	return (quick_instruction_sequence);
}
