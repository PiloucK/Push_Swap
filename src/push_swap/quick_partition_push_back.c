/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_partition_push_back.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 17:47:25 by clkuznie          #+#    #+#             */
/*   Updated: 2021/04/30 17:47:46 by clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void
quick_partition_push_back(t_quick_sort_loop_params *params, size_t pushed_len,
	int current_stack_index)
{
	t_list	*last_quick_instruction;

	if (!params->quick_instruction_sequence)
		return ;
	while (pushed_len)
	{
		last_quick_instruction = ft_lstlast(params->quick_instruction_sequence);
		params->quick_instruction_sequence->content++;
		last_quick_instruction->next = ft_lstnew(
			(void *)(size_t)(PB * current_stack_index + PA * !current_stack_index));
		if (!last_quick_instruction->next)
		{
			quick_sort_exit(params);
			return ;
		}
		(*params->instruction_array[
			(size_t)last_quick_instruction->next->content])(params->stack);
		debug_print_stack(params->stack, "quick_stack_sort_push_back",
			params->debug_option, last_quick_instruction->next);
		pushed_len--;
	}
}
