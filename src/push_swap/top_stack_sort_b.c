/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   top_stack_sort_b.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 17:55:32 by clkuznie          #+#    #+#             */
/*   Updated: 2021/04/30 17:55:33 by clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*
top_stack_sort_b(int **stack, int current_stack_index, size_t partition_len, t_list **top_instruction_sequence)
{
	t_list	*next_instruction;
	static size_t	rotation_count;
	// int		case_index;

	if (stack[current_stack_index][1] < stack[current_stack_index][2])
		next_instruction = ft_lstnew((void *)SB);
	else if (rotation_count != partition_len - 1
		&& !array_is_descending(stack[current_stack_index] + 1,
			partition_len - rotation_count))
	{
		rotation_count++;
		next_instruction = ft_lstnew((void *)RB);
	}
	else if (rotation_count)
	{
		rotation_count--;
		next_instruction = ft_lstnew((void *)RRB);
	}
	else
		return (NULL);
	if (!next_instruction)
		ft_lstclear(top_instruction_sequence, sequence_elem_delete_function);
	return (next_instruction);
}
