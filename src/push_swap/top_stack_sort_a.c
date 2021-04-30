/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   top_stack_sort_a.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 17:55:18 by clkuznie          #+#    #+#             */
/*   Updated: 2021/04/30 17:55:19 by clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*
top_stack_sort_a(int **stack, int current_stack_index, size_t partition_len, t_list **top_instruction_sequence)
{
	t_list	*next_instruction;
	static size_t	rotation_count;
	// int		case_index;

	if (stack[current_stack_index][1] > stack[current_stack_index][2])
		next_instruction = ft_lstnew((void *)SA);
	else if (rotation_count != partition_len - 1
		&& !array_is_ascending(stack[current_stack_index] + 1,
			partition_len - rotation_count))
	{
		rotation_count++;
		next_instruction = ft_lstnew((void *)RA);
	}
	else if (rotation_count)
	{
		rotation_count--;
		next_instruction = ft_lstnew((void *)RRA);
	}
	else
		return (NULL);
	if (!next_instruction)
		ft_lstclear(top_instruction_sequence, sequence_elem_delete_function);
	return (next_instruction);
}
