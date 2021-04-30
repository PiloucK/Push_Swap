/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_partition_push.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 17:46:34 by clkuznie          #+#    #+#             */
/*   Updated: 2021/04/30 17:46:41 by clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list		*
quick_partition_push(t_quick_sort_loop_params *params, int current_stack_index, float partition_median, size_t partition_len)
{
	t_list	*last_quick_instruction;
	size_t	i;
	size_t	rotate_count;
	size_t	next_partition_len;

	i = 1;
	rotate_count = 0;
	next_partition_len = partition_len / 2;
	while (next_partition_len)
	{
		last_quick_instruction = ft_lstlast(params->quick_instruction_sequence);
		if (((float)params->stack[current_stack_index][i] < partition_median && !current_stack_index)
			|| ((float)params->stack[current_stack_index][i] > partition_median && current_stack_index))
		{
			params->quick_instruction_sequence->content++;
			last_quick_instruction->next = ft_lstnew(
				(void *)(size_t)(PB * !current_stack_index + PA * current_stack_index));
			if (!last_quick_instruction->next)
				return (quick_sort_exit(params));
			(*params->instruction_array[
				(size_t)last_quick_instruction->next->content])(params->stack);
			debug_print_stack(params->stack, "quick_stack_sort_partitionning",
				params->debug_option, last_quick_instruction->next);
			next_partition_len--;
		}
		else
		{
			rotate_count++;
			params->quick_instruction_sequence->content++;
			last_quick_instruction->next = ft_lstnew(
				(void *)(size_t)(RA * !current_stack_index + RB * current_stack_index));
			if (!last_quick_instruction->next)
				return (quick_sort_exit(params));
			// if (partition_len == (unsigned int)params->stack[2][0] && (unsigned int)params->stack[!current_stack_index][0] > 1
			// 	&& (!current_stack_index && params->stack[!current_stack_index][1] < 
			// 		partition_median_get(params->stack[3], params->stack[3][1], partition_len / 2)
			// 		&& params->stack[!current_stack_index][1] < params->stack[!current_stack_index][2]))
			// 	last_quick_instruction->next->content = (void *)RR;
			(*params->instruction_array[
				(size_t)last_quick_instruction->next->content])(params->stack);
			debug_print_stack(params->stack, "quick_stack_sort_partitionning",
				params->debug_option, last_quick_instruction->next);
		}
	}
	while (rotate_count && partition_len - partition_len / 2 != (unsigned int)params->stack[current_stack_index][0])
	{
		last_quick_instruction = ft_lstlast(params->quick_instruction_sequence);
		rotate_count--;
		params->quick_instruction_sequence->content++;
		last_quick_instruction->next = ft_lstnew(
			(void *)(size_t)(RRA * !current_stack_index + RRB * current_stack_index));
		if (!last_quick_instruction->next)
			return (quick_sort_exit(params));
		(*params->instruction_array[
			(size_t)last_quick_instruction->next->content])(params->stack);
		debug_print_stack(params->stack, "quick_stack_sort_partitionning",
			params->debug_option, last_quick_instruction->next);
	}
	return (params->quick_instruction_sequence);
}
