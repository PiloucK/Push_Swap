/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_apply.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 20:00:03 by clkuznie          #+#    #+#             */
/*   Updated: 2021/04/20 15:40:22 by clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void
sort_apply(int *stack[3], t_instruction_function instruction_array[256],
	t_list **best_instruction_sequence, int debug_option)
{
	t_list	*instruction_sequence;

	*best_instruction_sequence = ft_lstnew((void *)-1);
	if (!*best_instruction_sequence)
		return ;
	instruction_sequence = bubble_stack_sort(stack, instruction_array,
		*best_instruction_sequence, debug_option);
	sort_save_best(best_instruction_sequence, instruction_sequence);
	instruction_sequence = quick_stack_sort(stack, instruction_array,
		*best_instruction_sequence, debug_option);
	sort_save_best(best_instruction_sequence, instruction_sequence);
}
