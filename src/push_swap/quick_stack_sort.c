/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_stack_sort.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 10:26:21 by clkuznie          #+#    #+#             */
/*   Updated: 2021/04/21 22:33:24 by clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_list
*quick_sort_exit(t_list **wrong_sequence)
{
	ft_lstclear(wrong_sequence, sequence_elem_delete_function);
	return (NULL);
}

static t_list	*
instruction_sequence_concat(t_list *subsequence_a, t_list *subsequence_b)
{
	t_list	*subsequence_a_last_elem;
	t_list	*subsequence_len_elem;

	subsequence_len_elem = subsequence_b;
	subsequence_a_last_elem = ft_lstlast(subsequence_a);
	subsequence_a->content = (void *)((long)subsequence_a->content
		+ (long)subsequence_b->content);
	subsequence_a_last_elem->next = subsequence_b->next;
	ft_lstdelone(subsequence_len_elem, sequence_elem_delete_function);
	return (subsequence_a);
}

t_list	*
instruction_simplifier_init(t_list *subsequence_a, t_list *subsequence_b,
	t_list **long_subsequence, t_list **short_subsequence)
{
	t_list	*final_subsequence;

	if (subsequence_a && subsequence_b)
	{
		if ((long)subsequence_a->content > (long)subsequence_b->content)
		{
			final_subsequence = subsequence_a;
			*long_subsequence = subsequence_a->next;
			*short_subsequence = subsequence_b->next;
		}
		else
		{
			final_subsequence = subsequence_b;
			*long_subsequence = subsequence_b->next;
			*short_subsequence = subsequence_a->next;
		}
	}
	else if (subsequence_a)
		final_subsequence = subsequence_a;
	else
		final_subsequence = subsequence_b;
	return (final_subsequence);
}

void
instruction_simplifier_finish(t_list *final_subsequence,
	t_list *short_subsequence)
{
	t_list	*final_subsequence_last_instruction;

	final_subsequence_last_instruction = ft_lstlast(final_subsequence);
	if (final_subsequence_last_instruction)
	{
		final_subsequence->content = (void *)((long)final_subsequence->content
			+ (long)ft_lstsize(short_subsequence));
		while (short_subsequence)
		{
			final_subsequence_last_instruction = short_subsequence;
			short_subsequence = short_subsequence->next;
			final_subsequence_last_instruction =
				final_subsequence_last_instruction->next;
		}
	}
}

static t_list	*
instruction_sequence_simplifier(t_list *subsequence_a, t_list *subsequence_b)
{
	t_list	*final_subsequence;
	t_list	*long_subsequence;
	t_list	*short_subsequence;
	long	best_instruction_index;

	final_subsequence = instruction_simplifier_init(subsequence_a,
		subsequence_b, &long_subsequence, &short_subsequence);
	while (long_subsequence && short_subsequence)
	{
		best_instruction_index = (long)long_subsequence->content
			+ (long)short_subsequence->content;
		if (best_instruction_index == RR || best_instruction_index == RRR
			|| best_instruction_index == SS)
		{
			long_subsequence->content = (void *)best_instruction_index;
			long_subsequence = long_subsequence->next;
			short_subsequence = short_subsequence->next;
		}
		else
			long_subsequence = long_subsequence->next;
	}
	instruction_simplifier_finish(final_subsequence, short_subsequence);
	return (final_subsequence);
}

float
partition_median_get(int *stack, long start_value, long partition_len)
{
	long	i;
	long	j;
	
	i = 1;
	while (stack[i] != start_value)
		i++;
	j = 0;
	while (j < partition_len / 2)
		j++;
	if (partition_len % 2)
		return (stack[i + j]);
	return (
		(stack[i + j] + stack[i + j + 1]) / 2.0
	);
}

int
array_smallest(int *array, size_t array_len)
{
	size_t	i;
	int		smallest_value;

	i = 0;
	smallest_value = array[0];
	while (i != array_len)
	{
		if (array[array_len] < smallest_value)
			smallest_value = array[array_len];
		i++;
	}
	return (smallest_value);
}

static size_t
quick_sort_partitionning(t_quick_sort_loop_params params,
	int current_stack_index)
{
	size_t	next_partition_len;
	float	partition_median;
	t_list	*last_quick_instruction;

	if (params.partition_len <= 3)
	   return (0);
	partition_median = partition_median_get(params.stack[current_stack_index],
		array_smallest(&params.stack[current_stack_index][1],
			params.partition_len), params.partition_len);
	next_partition_len = params.partition_len / 2;
	while (next_partition_len)
	{
		last_quick_instruction = ft_lstlast(params.quick_instruction_sequence);
		next_partition_len--;
	}
	return (params.partition_len / 2);
}

static t_list	*
quick_sort_recursive_loop(t_quick_sort_loop_params params)
{
	t_list						*instruction_subsequence;
	size_t						instruction_index;
	static int					current_stack_index;
	size_t						next_partition_len;
	t_quick_sort_loop_params	next_params;

	next_partition_len = quick_sort_partitionning(params,
		current_stack_index);
	if (next_partition_len)
	{
		next_params = params;
		next_params.partition_len -= next_partition_len;
		instruction_subsequence = quick_sort_recursive_loop(params);
		next_params.partition_len = next_partition_len;
		instruction_subsequence = instruction_sequence_simplifier(
			instruction_subsequence, quick_sort_recursive_loop(params));
	}
	// instruction_index = 0;
	// next_instruction = ft_lstnew((void *)instruction_index);
	// if (!instruction_index || !next_instruction)
	// 	return (quick_sort_exit(&quick_instruction_sequence));
	// (*instruction_array[instruction_index])(stack);
	// quick_instruction_sequence->content++;
	// ft_lstadd_back(&quick_instruction_sequence, next_instruction);
	// debug_print_stack(stack, "quick_stack_sort", debug_option,
	// 	next_instruction);
	current_stack_index = !current_stack_index;
	return (instruction_subsequence);
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
			(size_t)best_instruction_sequence->content
			< (size_t)quick_instruction_sequence->content)
			return (quick_sort_exit(&quick_instruction_sequence));
	}
	return (quick_instruction_sequence);
}
