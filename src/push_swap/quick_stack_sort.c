/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_stack_sort.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 10:26:21 by clkuznie          #+#    #+#             */
/*   Updated: 2021/04/22 18:13:40 by clkuznie         ###   ########.fr       */
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

	if (!subsequence_a || !subsequence_b)
	{
		ft_lstclear(&subsequence_a, sequence_elem_delete_function);
		ft_lstclear(&subsequence_b, sequence_elem_delete_function);
		return (NULL);
	}
	subsequence_len_elem = subsequence_b;
	subsequence_a_last_elem = ft_lstlast(subsequence_a);
	subsequence_a->content = (void *)((long)subsequence_a->content
		+ (long)subsequence_b->content);
	subsequence_a_last_elem->next = subsequence_b->next;
	ft_lstdelone(subsequence_len_elem, sequence_elem_delete_function);
	return (subsequence_a);
}

// t_list	*
// instruction_simplifier_init(t_list *subsequence_a, t_list *subsequence_b,
// 	t_list **long_subsequence, t_list **short_subsequence)
// {
// 	t_list	*final_subsequence;

// 	if (subsequence_a && subsequence_b)
// 	{
// 		if ((long)subsequence_a->content > (long)subsequence_b->content)
// 		{
// 			final_subsequence = subsequence_a;
// 			*long_subsequence = subsequence_a->next;
// 			*short_subsequence = subsequence_b->next;
// 		}
// 		else
// 		{
// 			final_subsequence = subsequence_b;
// 			*long_subsequence = subsequence_b->next;
// 			*short_subsequence = subsequence_a->next;
// 		}
// 	}
// 	else if (subsequence_a)
// 		final_subsequence = subsequence_a;
// 	else
// 		final_subsequence = subsequence_b;
// 	return (final_subsequence);
// }

// void
// instruction_simplifier_finish(t_list *final_subsequence,
// 	t_list *short_subsequence)
// {
// 	t_list	*final_subsequence_last_instruction;

// 	final_subsequence_last_instruction = ft_lstlast(final_subsequence);
// 	if (final_subsequence_last_instruction)
// 	{
// 		final_subsequence->content = (void *)((long)final_subsequence->content
// 			+ (long)ft_lstsize(short_subsequence));
// 		while (short_subsequence)
// 		{
// 			final_subsequence_last_instruction = short_subsequence;
// 			short_subsequence = short_subsequence->next;
// 			final_subsequence_last_instruction =
// 				final_subsequence_last_instruction->next;
// 		}
// 	}
// }

// static t_list	*
// instruction_sequence_simplifier(t_list *subsequence_a, t_list *subsequence_b)
// {
// 	t_list	*final_subsequence;
// 	t_list	*long_subsequence;
// 	t_list	*short_subsequence;
// 	long	best_instruction_index;

// 	final_subsequence = instruction_simplifier_init(subsequence_a,
// 		subsequence_b, &long_subsequence, &short_subsequence);
// 	while (long_subsequence && short_subsequence)
// 	{
// 		best_instruction_index = (long)long_subsequence->content
// 			+ (long)short_subsequence->content;
// 		if (best_instruction_index == RR || best_instruction_index == RRR
// 			|| best_instruction_index == SS)
// 		{
// 			long_subsequence->content = (void *)best_instruction_index;
// 			long_subsequence = long_subsequence->next;
// 			short_subsequence = short_subsequence->next;
// 		}
// 		else
// 			long_subsequence = long_subsequence->next;
// 	}
// 	instruction_simplifier_finish(final_subsequence, short_subsequence);
// 	return (final_subsequence);
// }

float
partition_median_get(int *stack, long start_value, long partition_len)
{
	long	i;
	long	j;
	
	i = 0;
	while (stack[i + 1] != start_value)
		i++;
	j = 0;
	while (j < partition_len / 2)
		j++;
	if (partition_len % 2)
		return (stack[i + j + 1]);
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
		if (array[i] < smallest_value)
			smallest_value = array[i];
		i++;
	}
	return (smallest_value);
}

int
array_biggest(int *array, size_t array_len)
{
	size_t	i;
	int		biggest_value;

	i = 0;
	biggest_value = array[0];
	while (i != array_len)
	{
		if (array[i] > biggest_value)
			biggest_value = array[i];
		i++;
	}
	return (biggest_value);
}

t_list		*
quick_partition_push(t_quick_sort_loop_params *params, int current_stack_index,
	float partition_median, size_t partition_len)
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
				return (quick_sort_exit(&params->quick_instruction_sequence));
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
				return (quick_sort_exit(&params->quick_instruction_sequence));
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
			return (quick_sort_exit(&params->quick_instruction_sequence));
		(*params->instruction_array[
			(size_t)last_quick_instruction->next->content])(params->stack);
		debug_print_stack(params->stack, "quick_stack_sort_partitionning",
			params->debug_option, last_quick_instruction->next);
	}
	return (params->quick_instruction_sequence);
}

static size_t
quick_sort_partitionning(t_quick_sort_loop_params *params,
	int current_stack_index, size_t partition_len)
{
	size_t	next_partition_len;
	float	partition_median;

	if (partition_len <= 3)
	   return (0);
	partition_median = partition_median_get(params->stack[3],
		array_smallest(&params->stack[current_stack_index][1],
			partition_len), partition_len);
	next_partition_len = partition_len / 2;
	if (!quick_partition_push(params, current_stack_index, partition_median,
		partition_len))
		quick_sort_exit(&params->quick_instruction_sequence);
	return (next_partition_len);
}

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
			quick_sort_exit(&params->quick_instruction_sequence);
			return ;
		}
		(*params->instruction_array[
			(size_t)last_quick_instruction->next->content])(params->stack);
		debug_print_stack(params->stack, "quick_stack_sort_push_back",
			params->debug_option, last_quick_instruction->next);
		pushed_len--;
	}
}

size_t
quick_sort_two(int **stack, int current_stack_index)
{
	return (
		(size_t)((((stack[current_stack_index][1] > stack[current_stack_index][2])
			&& !current_stack_index) || ((stack[current_stack_index][1] < stack[current_stack_index][2]) && current_stack_index))
			* (SA * !current_stack_index + SB * current_stack_index))
	);
}

size_t
quick_sort_three_clean(int **stack, int current_stack_index)
{
	if (array_biggest(stack[current_stack_index] + 1, 3)
		== stack[current_stack_index][2])
		return (
			(size_t)(RRA * !current_stack_index + RRB * current_stack_index)
		);
	return (
		(size_t)((stack[current_stack_index][1] > stack[current_stack_index][2])
			* (SA * !current_stack_index + SB * current_stack_index))
	);
}

size_t
quick_sort_three_crap(int **stack, int current_stack_index, int rotation_count)
{
	if (!rotation_count && array_biggest(stack[current_stack_index] + 1, 3) == stack[current_stack_index][2])
		return (
			(size_t)(RA * !current_stack_index + RB * current_stack_index)
		);
	else if (rotation_count)
		return (
			(size_t)((stack[current_stack_index][1] > stack[current_stack_index][2])
				* (SA * !current_stack_index + SB * current_stack_index)
				+ (stack[current_stack_index][1] < stack[current_stack_index][2])
				* (RRA * !current_stack_index + RRB * current_stack_index))
		);
	return (
		(size_t)((stack[current_stack_index][1] > stack[current_stack_index][2])
			* (SA * !current_stack_index + SB * current_stack_index))
	);
}

t_list		*
quick_apply(t_quick_sort_loop_params *params, size_t instruction_index,
	int *rotation_count, t_list **instruction_subsequence)
{
	t_list	*next_instruction;

	if (instruction_index == RA || instruction_index == RB)
		++*rotation_count;
	else if (instruction_index == RRA || instruction_index == RRB)
		--*rotation_count;
	if (!instruction_index)
		return (*instruction_subsequence);
	next_instruction = ft_lstnew((void *)instruction_index);
	if (!next_instruction)
	{
		quick_sort_exit(&params->quick_instruction_sequence);
		return (quick_sort_exit(instruction_subsequence));
	}
	(*params->instruction_array[instruction_index])(params->stack);
	(*instruction_subsequence)->content++;
	ft_lstadd_back(instruction_subsequence, next_instruction);
	debug_print_stack(params->stack, "quick_apply", params->debug_option,
		next_instruction);
	return (*instruction_subsequence);
}

t_list		*
quick_sort_best_sequence(t_quick_sort_loop_params *params, size_t partition_len,
	int current_stack_index)
{
	t_list	*instruction_subsequence;
	size_t	instruction_index;
	int		rotation_count;

	instruction_subsequence = ft_lstnew((void *)0);
	instruction_index = 1;
	rotation_count = 0;
	while (instruction_subsequence && instruction_index)
	{
		if ((unsigned int)params->stack[current_stack_index][0]
			== partition_len && partition_len == 3)
			instruction_index = quick_sort_three_clean(params->stack,
				current_stack_index);
		else if (partition_len == 2)
			instruction_index =
				quick_sort_two(params->stack, current_stack_index);
		else
			instruction_index = quick_sort_three_crap(
				params->stack, current_stack_index, rotation_count);
		quick_apply(params, instruction_index, &rotation_count,
			&instruction_subsequence);
	}
	return (instruction_subsequence);
}

static t_list	*
quick_sort_recursive_loop(t_quick_sort_loop_params *params, size_t partition_len)
{
	t_list						*instruction_subsequence;
	static int					current_stack_index;
	size_t						next_partition_len;

	next_partition_len = quick_sort_partitionning(params,
		current_stack_index, partition_len);
	if (!params->quick_instruction_sequence)
		return (NULL);
	if (next_partition_len)
	{
		instruction_subsequence = quick_sort_recursive_loop(params,
			partition_len - next_partition_len);
		instruction_subsequence = instruction_sequence_concat(
			instruction_subsequence, quick_sort_recursive_loop(params,
				next_partition_len));
		instruction_sequence_concat(params->quick_instruction_sequence,
			instruction_subsequence);
		quick_partition_push_back(params, next_partition_len, current_stack_index);
	}
	else
		instruction_subsequence = quick_sort_best_sequence(params,
			partition_len, current_stack_index);
	current_stack_index = !current_stack_index;
	return (params->quick_instruction_sequence);
}

/*
 *	Because of 42 Norme limitation and the personnal objective to not use
 *	structs in this sort algorithm the sequence will be calculated entirely
 *	even if the number of instructions already exceeds the best calculated
 *	sequence length.
 *	Easily added where instructions are applied in a similar maner as did in
 *	the custom extraction_sort algorithm in this project.
*/
t_list
*quick_stack_sort(int *stack[4], t_instruction_function instruction_array[256],
	t_list *best_instruction_sequence, int debug_option)
{
	t_list						*quick_instruction_sequence;
	t_quick_sort_loop_params	initial_params;

	(void)best_instruction_sequence;
	stack_reset(stack);
	quick_instruction_sequence = ft_lstnew((void *)0);
	if (!quick_instruction_sequence)
		return (NULL);
	debug_print_stack(stack, "quick_stack_sort", debug_option, NULL);
	if (!stack_is_sorted(stack[0]))
	{
		initial_params.stack = stack;
		initial_params.debug_option = debug_option;
		initial_params.instruction_array = instruction_array;
		initial_params.quick_instruction_sequence = quick_instruction_sequence;
		if (quick_sort_recursive_loop(&initial_params, stack[0][0]))
		{
			ft_printf("toto-------------------------\n");
			print_best_instruction_sequence(quick_instruction_sequence);
			ft_printf("toto-------------------------\n");
			// || (size_t)best_instruction_sequence->content          TODO;    CHECK SIZE IN INSTRUCTION ADDITION FUNCITONS
			// 	< (size_t)quick_instruction_sequence->content)
			return (NULL);
		}
	}
	return (quick_instruction_sequence);
}
