/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_apply.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 20:00:03 by clkuznie          #+#    #+#             */
/*   Updated: 2021/04/19 16:59:46 by clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int
util_stack_smallest(int *stack[3], int current)
{
	int		i;

	i = 1;
	while (i <= stack[2][0])
	{
		if (stack[2][i] < current)
			return (0);
		i++;
	}
	return (1);
}

int
util_stack_biggest(int *stack[3], int current)
{
	int		i;

	i = 1;
	while (i <= stack[2][0])
	{
		if (stack[2][i] > current)
			return (0);
		i++;
	}
	return (1);
}

long
bubble_sort_next_instruction(int *stack[3])
{
	if (stack[0][1] > stack[0][2] && !(util_stack_biggest(stack, stack[0][1])
		&& util_stack_smallest(stack, stack[0][2])))
		return (SA);
	return (RA);
}

t_list	*
sort_exit(t_list **wrong_sequence)
{
	ft_lstclear(wrong_sequence, sequence_elem_delete_function);
	return (NULL);
}

t_list	*
bubble_sort_apply(int *stack[3], t_instruction_function instruction_array[256],
	t_list *best_instruction_sequence)
{
	t_list	*bubble_instruction_sequence;
	t_list	*next_instruction;
	long	instruction_index;

	bubble_instruction_sequence = ft_lstnew((void *)0);
	if (!bubble_instruction_sequence)
		return (NULL);
	while(!stack_is_sorted(stack[0]))
	{
		instruction_index = bubble_sort_next_instruction(stack);
		next_instruction = ft_lstnew((void *)instruction_index);
		if (!next_instruction || bubble_instruction_sequence->content
			== best_instruction_sequence->content)
			return (sort_exit(&bubble_instruction_sequence));
		(*instruction_array[instruction_index])(stack);
		bubble_instruction_sequence->content++;
		ft_lstadd_back(&bubble_instruction_sequence, next_instruction);
// print_stack_column(stack); DEBUG MODE PREVIEW
	}
	return (bubble_instruction_sequence);
}

void
sort_save_best(t_list **best_instruction_sequence,
	t_list *instruction_sequence)
{
	if (instruction_sequence)
	{
		ft_lstclear(best_instruction_sequence, sequence_elem_delete_function);
		*best_instruction_sequence = instruction_sequence;
	}
}

void
sort_apply(int *stack[3], t_instruction_function instruction_array[256],
	t_list **best_instruction_sequence)
{
	t_list	*instruction_sequence;

	*best_instruction_sequence = ft_lstnew((void *)-1);
	if (!*best_instruction_sequence)
		return ;
	instruction_sequence = bubble_sort_apply(stack, instruction_array,
		*best_instruction_sequence);
	sort_save_best(best_instruction_sequence, instruction_sequence);
}
