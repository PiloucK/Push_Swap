/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_stack_sort.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 10:26:21 by clkuznie          #+#    #+#             */
/*   Updated: 2021/04/30 17:57:47 by clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list
*quick_stack_sort(int *stack[4], t_instruction_function instruction_array[256],
	t_list *best_instruction_sequence, int debug_option)
{
	t_quick_sort_loop_params	initial_params;

	stack_reset(stack);
	initial_params.quick_instruction_sequence = ft_lstnew((void *)0);
	if (!initial_params.quick_instruction_sequence)
		return (NULL);
	debug_print_stack(stack, "quick_stack_sort", debug_option, NULL);
	if (!array_is_ascending(stack[0] + 1, stack[0][0]))
	{
		initial_params.stack = stack;
		initial_params.debug_option = debug_option;
		initial_params.instruction_array = instruction_array;
		if (init_stack_malloc(initial_params.stack_copy, stack[2][0]))
			return (quick_sort_exit(&initial_params));
		instruction_sequence_concat(initial_params.quick_instruction_sequence,
			quick_sort_recursive_loop(&initial_params, stack[0][0],
				stack[0][0]));
		if (initial_params.quick_instruction_sequence)
		{
			if (best_instruction_sequence->content
				< initial_params.quick_instruction_sequence->content)
				return (quick_sort_exit(&initial_params));
		}
	}
	quick_push_cleanup(initial_params.quick_instruction_sequence);
	return (initial_params.quick_instruction_sequence);
}
