/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_stack_sort.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 10:26:21 by clkuznie          #+#    #+#             */
/*   Updated: 2021/04/21 18:09:46 by clkuznie         ###   ########.fr       */
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

static int
quick_sort_partitionning(int *stack[4], int current_stack_index,
	int partition_len)
{
	int		next_partition_len;

	if (partition_len <= 3)
		return (0);
	return (partition_len);
}

static t_list	*
quick_sort_recursive_loop(
	int *stack[4],
	t_instruction_function instruction_array[256],
	t_list *quick_instruction_sequence,
	int partition_len)
{
	t_list		*instruction_subsequence;
	long		instruction_index;
	static int	current_stack_index;
	int			next_partition_len;

	next_partition_len = quick_sort_partitionning(stack, current_stack_index,
		partition_len);
	if (next_partition_len)
	{
		instruction_subsequence = quick_sort_recursive_loop(stack,
			instruction_array, quick_instruction_sequence, next_partition_len);
		instruction_subsequence = instruction_sequence_simplifier(
			instruction_subsequence, quick_sort_recursive_loop(stack,
				instruction_array, quick_instruction_sequence,
				partition_len - next_partition_len));
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
			(long)best_instruction_sequence->content
			< (long)quick_instruction_sequence->content)
			return (quick_sort_exit(&quick_instruction_sequence));
	}
	return (quick_instruction_sequence);
}
