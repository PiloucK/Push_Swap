/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_stack_sort.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 10:26:21 by clkuznie          #+#    #+#             */
/*   Updated: 2021/04/29 14:25:53 by clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_list
*quick_sort_exit(t_list **wrong_sequence)
{
	ft_lstclear(wrong_sequence, sequence_elem_delete_function);
	return (NULL);
}

void
sequence_elem_debug_print(void *elem_content)
{
	if ((long)elem_content == PA)
		write(1, " - pa", 5);
	else if ((long)elem_content == PB)
		write(1, " - pb", 5);
	else if ((long)elem_content == RA)
		write(1, " - ra", 5);
	else if ((long)elem_content == RB)
		write(1, " - rb", 5);
	else if ((long)elem_content == RR)
		write(1, " - rr", 5);
	else if ((long)elem_content == RRA)
		write(1, " - rra", 6);
	else if ((long)elem_content == RRB)
		write(1, " - rrb", 6);
	else if ((long)elem_content == RRR)
		write(1, " - rrr", 6);
	else if ((long)elem_content == SA)
		write(1, " - sa", 5);
	else if ((long)elem_content == SB)
		write(1, " - sb", 5);
	else if ((long)elem_content == SS)
		write(1, " - ss", 5);
}

void
debug_print_sequence(t_list *sequence)
{
	char	interactive_tmp_buf[1];
	if (sequence)
	{
		ft_printf("len: %d sequence:", (int)(size_t)(sequence->content));
		ft_lstiter(sequence->next, sequence_elem_debug_print);
		write(1, "\n", 1);
	}
	read(0, interactive_tmp_buf, 1);
}

static t_list	*
instruction_sequence_concat(t_list *subsequence_a, t_list *subsequence_b)
{
	if (!subsequence_a || !subsequence_b)
	{
		if (subsequence_a)
			return (subsequence_a);
		else if (subsequence_b)
			return (subsequence_b);
		return (NULL);
	}
	ft_lstadd_back(&subsequence_a, subsequence_b->next);
	subsequence_a->content = (void *)((long)subsequence_a->content
		+ (long)subsequence_b->content);
	free(subsequence_b);
	return (subsequence_a);
}

void
instruction_merge_init(t_list *subsequence_a, t_list *subsequence_b,
	t_list **longer_subsequence, t_list **shorter_subsequence)
{
	*longer_subsequence = NULL;
	*shorter_subsequence = NULL;
	if (subsequence_a && subsequence_b)
	{
		if ((size_t)subsequence_a->content > (size_t)subsequence_b->content
			|| (subsequence_a->content == subsequence_b->content && (size_t)subsequence_a->content == 4
			&& ((size_t)subsequence_a->next->content == SA || (size_t)subsequence_a->next->content == SB)))
		{
			*longer_subsequence = subsequence_a;
			*shorter_subsequence = subsequence_b->next;
			free(subsequence_b);
		}
		else
		{
			*longer_subsequence = subsequence_b;
			*shorter_subsequence = subsequence_a->next;
			free(subsequence_a);
		}
	}
	else if (subsequence_a)
		*longer_subsequence = subsequence_a;
	else
		*longer_subsequence = subsequence_b;
}

void
instruction_merge_finish(t_list *longer_subsequence,
	t_list *shorter_subsequence)
{
	while (longer_subsequence && shorter_subsequence)
	{
		ft_lstadd_back(&longer_subsequence, shorter_subsequence);
		shorter_subsequence = shorter_subsequence->next;
	}
}

void
instruction_sequence_merge_loop(t_list *longer_subsequence, t_list **shorter_subsequence)
{
	size_t	best_instruction_index;
	t_list	*trash_instruction;

	while (longer_subsequence && *shorter_subsequence)
	{
		best_instruction_index = (size_t)(longer_subsequence)->content
			+ (size_t)(*shorter_subsequence)->content;
		if (best_instruction_index == RR || best_instruction_index == RRR
			|| best_instruction_index == SS)
		{
			(longer_subsequence)->content = (void *)best_instruction_index;
			(longer_subsequence) = (longer_subsequence)->next;
			trash_instruction = (*shorter_subsequence);
			(*shorter_subsequence) = (*shorter_subsequence)->next;
			free(trash_instruction);
		}
		else
			(longer_subsequence) = (longer_subsequence)->next;
	}
}

static t_list	*
instruction_sequence_merge(t_list *subsequence_a, t_list *subsequence_b)
{
	t_list	*longer_subsequence;
	t_list	*shorter_subsequence;

	instruction_merge_init(subsequence_a,
		subsequence_b, &longer_subsequence, &shorter_subsequence);
	if (!longer_subsequence)
		return (NULL);
	instruction_sequence_merge_loop(longer_subsequence, &shorter_subsequence);
	instruction_merge_finish(longer_subsequence, shorter_subsequence);
	longer_subsequence->content = (void *)(size_t)ft_lstsize(longer_subsequence->next);
	return (longer_subsequence);
}

// static t_list	*
// instruction_sequence_merge_loop(t_list *subsequence_a, t_list *subsequence_b)
// {
// 	t_list	*longer_subsequence;
// 	t_list	*longer_subsequence;
// 	t_list	*shorter_subsequence;
// 	long	best_instruction_index;

// 	longer_subsequence = instruction_merge_init(subsequence_a,
// 		subsequence_b, &longer_subsequence, &shorter_subsequence);
// 	while (longer_subsequence && shorter_subsequence)
// 	{
// 		best_instruction_index = (size_t)longer_subsequence->content
// 			+ (size_t)shorter_subsequence->content;
// 		if (best_instruction_index == RR || best_instruction_index == RRR
// 			|| best_instruction_index == SS)
// 		{
// 			longer_subsequence->content = (void *)best_instruction_index;
// 			longer_subsequence = longer_subsequence->next;
// 			shorter_subsequence = shorter_subsequence->next;
// 		}
// 		else
// 			longer_subsequence = longer_subsequence->next;
// 	}
// 	instruction_merge_finish(longer_subsequence, shorter_subsequence);
// 	return (longer_subsequence);
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

void
array_print_int(int *array, size_t array_len)
{
	size_t	i;

	i = 0;
	write(1, "| ", 2);
	while (i < array_len)
	{
		ft_printf("%d |", array[i]);
		i++;
	}
	write(1, "\n", 1);
}

int
array_is_ascending(int *array, size_t array_len)
{
	size_t	i;

// ft_printf("ascend = ");
// array_print_int(array, array_len);
	i = 0;
	while (i < array_len - 1)
	{
		if (array[i] > array[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int
array_is_descending(int *array, size_t array_len)
{
	size_t	i;

// ft_printf("descend = ");
// array_print_int(array, array_len);
	i = 0;
	while (i < array_len - 1)
	{
		if (array[i] < array[i + 1])
			return (0);
		i++;
	}
	return (1);
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
			// printf("%f\n", partition_median_get(params->stack[3], params->stack[3][1], partition_len / 2));
			if (partition_len == (unsigned int)params->stack[2][0] && (unsigned int)params->stack[!current_stack_index][0] > 1
				&& (!current_stack_index && params->stack[!current_stack_index][1] < 
					partition_median_get(params->stack[3], params->stack[3][1], partition_len / 2)
					&& params->stack[!current_stack_index][1] < params->stack[!current_stack_index][2]))
				last_quick_instruction->next->content = (void *)RR;
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
	if ((array_is_ascending(params->stack[current_stack_index] + 1,
			partition_len) && !current_stack_index)
		|| (array_is_descending(params->stack[current_stack_index] + 1,
			partition_len) && current_stack_index))
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

int		*
best_two_sequence_return(int sequence_index, int current_stack_index)
{
	static int	best_sequences[6][5] = {
		{0, 0, 0, 0, 0},
		{SA, 0, 0, 0, 0},
		{RA, 0, 0, 0, 0},
		{0, 0, 0, 0, 0},
		{SB, 0, 0, 0, 0},
		{RB, 0, 0, 0, 0}
	};
	return (best_sequences[sequence_index + current_stack_index * 3]);
}

int		*
best_crap_sequence_return(int sequence_index, int current_stack_index)
{
	static int	best_sequences[12][5] = {
		{0, 0, 0, 0, 0},
		{RA, SA, RRA, 0, 0},
		{SA, 0, 0, 0, 0},
		{RA, SA, RRA, SA, 0},
		{SA, RA, SA, RRA, 0},
		{SA, RA, SA, RRA, SA},
		{SB, RB, SB, RRB, SB},
		{SB, RB, SB, RRB, 0},
		{RB, SB, RRB, SB, 0},
		{SB, 0, 0, 0, 0},
		{RB, SB, RRB, 0, 0},
		{0, 0, 0, 0, 0}
	};
	return (best_sequences[sequence_index + current_stack_index * 6]);
}

int		*
best_clean_sequence_return(int sequence_index, int current_stack_index)
{
	static int	best_sequences[12][5] = {
		{0, 0, 0, 0, 0},
		{RRA, SA, 0, 0, 0},
		{SA, 0, 0, 0, 0},
		{RRA, 0, 0, 0, 0},
		{RA, 0, 0, 0, 0},
		{RA, SA, 0, 0, 0},
		{RB, SB, 0, 0, 0},
		{RB, 0, 0, 0, 0},
		{RRB, 0, 0, 0, 0},
		{SB, 0, 0, 0, 0},
		{RRB, SB, 0, 0, 0},
		{0, 0, 0, 0, 0}
	};
	return (best_sequences[sequence_index + current_stack_index * 6]);
}

int
find_best_sequence_index(int **stack, int current_stack_index)
{
	int		i;

	i = !(stack[current_stack_index][1] < stack[current_stack_index][3]) * 3;

	if (!i)
		return (i
			+ (stack[current_stack_index][2] > stack[current_stack_index][3])
			+ ((stack[current_stack_index][2] < stack[current_stack_index][3])
			&& (stack[current_stack_index][1] > stack[current_stack_index][2]))
			* 2);
	return (i
		+ (stack[current_stack_index][2] < stack[current_stack_index][3])
		+ ((stack[current_stack_index][1] > stack[current_stack_index][2])
		&& (stack[current_stack_index][2] > stack[current_stack_index][3]))
		* 2);
}

int		*
quick_sort_two(int **stack, int current_stack_index)
{
	int		sequence_index;
	int		opposite_index;

	sequence_index = (!current_stack_index && stack[current_stack_index][1]
		> stack[current_stack_index][2])
			|| (current_stack_index && stack[current_stack_index][1]
		< stack[current_stack_index][2]);
	if (stack[!current_stack_index][0] != 3 || !sequence_index
		|| stack[current_stack_index][0] != 2)
		return (best_two_sequence_return(sequence_index, current_stack_index));
	opposite_index = find_best_sequence_index(stack, !current_stack_index);
	sequence_index += (opposite_index == 4 && current_stack_index)
		|| (opposite_index == 1 && !current_stack_index);
	return (best_two_sequence_return(sequence_index, current_stack_index));
}

int		*
quick_sort_three(int **stack, int current_stack_index,
	size_t last_partition_len)
{
	int		opposite_index;
	int		sequence_index;

	sequence_index = find_best_sequence_index(stack, current_stack_index);
	if (stack[current_stack_index][0] != 3)
		return (best_crap_sequence_return(sequence_index, current_stack_index));
	if (last_partition_len != 6 || stack[!current_stack_index][0] == 3)
		return (best_clean_sequence_return(sequence_index, current_stack_index));
	opposite_index = find_best_sequence_index(stack, !current_stack_index);
	if ((sequence_index == 1 && (opposite_index == 4 || opposite_index < 2) && !current_stack_index)
		|| (sequence_index == 4 && (opposite_index == 1 || opposite_index > 2) && current_stack_index))
		return (best_crap_sequence_return(sequence_index, current_stack_index));
	return (best_clean_sequence_return(sequence_index, current_stack_index));
}

void
quick_apply(t_quick_sort_loop_params *params, t_list *instruction_subsequence)
{
	if (!instruction_subsequence || !instruction_subsequence->content)
		return ;
	instruction_subsequence = instruction_subsequence->next;
	while (instruction_subsequence)
	{
		(*params->instruction_array[(size_t)instruction_subsequence->content])
			(params->stack);
		debug_print_stack(params->stack, "quick_apply", params->debug_option,
			instruction_subsequence);
		instruction_subsequence = instruction_subsequence->next;
	}
}

t_list		*
sequence_convert(t_quick_sort_loop_params *params, int *best_sequence)
{
	t_list	*instruction_subsequence;
	t_list	*next_instruction;
	int		i;

	instruction_subsequence = ft_lstnew((void *)0);
	if (!instruction_subsequence)
		return (quick_sort_exit(&params->quick_instruction_sequence));
	i = 0;
	while (i < 5 && best_sequence[i])
	{
		instruction_subsequence->content++;
		next_instruction = ft_lstnew((void *)(size_t)best_sequence[i]);
		if (!instruction_subsequence)
		{
			ft_lstclear(&instruction_subsequence,
				sequence_elem_delete_function);
			return (quick_sort_exit(&params->quick_instruction_sequence));
		}
		ft_lstadd_back(&instruction_subsequence, next_instruction);
		i++;
	}
	return (instruction_subsequence);
}

t_list		*
quick_sort_best_sequence(t_quick_sort_loop_params *params, size_t partition_len,
	int current_stack_index, size_t last_partition_len)
{
	int		*best_sequence;

	if (partition_len > 3)
		return (NULL);
	if (partition_len == 2)
		best_sequence = quick_sort_two(params->stack,
			current_stack_index);
	else
		best_sequence = quick_sort_three(params->stack,
			current_stack_index, last_partition_len);
	return (sequence_convert(params, best_sequence));
}

void
quick_delete_useless_push(t_list *quick_sort_best_sequence, t_list *first_push_b, t_list *valid_instruction, int push_to_skip)
{
	t_list	*last_valid_instruction;
	t_list	*to_delete;

	// debug_print_sequence(first_push_b);
	// debug_print_sequence(valid_instruction);
	// ft_printf("%d\n", push_to_skip);
	if (!quick_sort_best_sequence || !first_push_b)
		return ;
	// write(1, "push delete test\n", 18);
	while (push_to_skip-- > 0)
		first_push_b = first_push_b->next;
	last_valid_instruction = quick_sort_best_sequence;
	while (last_valid_instruction && last_valid_instruction->next != first_push_b)
		last_valid_instruction = last_valid_instruction->next;
	// debug_print_sequence(last_valid_instruction);
	// write(1, "deleted instrucitons\n", 22);
	last_valid_instruction->next = valid_instruction;
	while (first_push_b && first_push_b != valid_instruction)
	{
		to_delete = first_push_b;
		// ft_printf("%p\n", first_push_b);
		// sequence_elem_print_function(first_push_b->content);
		first_push_b = first_push_b->next;
		free(to_delete);
	}
	// write(1, "done_deleting\n", 15);

}

void
quick_push_cleanup(t_list *quick_sort_best_sequence)
{
	t_list	*potential_useless_push;
	t_list	*sequence_first;
	int		push_count;

	if (!quick_sort_best_sequence)
		return ;
	sequence_first = quick_sort_best_sequence;
	quick_sort_best_sequence = quick_sort_best_sequence->next;
	while (quick_sort_best_sequence)
	{
		push_count = 0;
		if ((size_t)quick_sort_best_sequence->content == PB && ++push_count)
			potential_useless_push = quick_sort_best_sequence;
		quick_sort_best_sequence = quick_sort_best_sequence->next;
		while (quick_sort_best_sequence
			&& (size_t)quick_sort_best_sequence->content == PB && ++push_count)
			quick_sort_best_sequence = quick_sort_best_sequence->next;
		while (quick_sort_best_sequence
			&& (size_t)quick_sort_best_sequence->content == PA && push_count--)
			quick_sort_best_sequence = quick_sort_best_sequence->next;
		quick_delete_useless_push(sequence_first, potential_useless_push, quick_sort_best_sequence, push_count);
		while (quick_sort_best_sequence
			&& (size_t)quick_sort_best_sequence->content != PB)
			quick_sort_best_sequence = quick_sort_best_sequence->next;
	}
}

// int
// is_sort_two_exception(int **stack, int current_stack_index,
// 	size_t last_partition_len)
// {
// 	if (last_partition_len != 5)
// 		return (0);
// 	if (!current_stack_index
// 		&& array_smallest(stack[!current_stack_index] + 1, 3)
// 			== stack[!current_stack_index][2]
// 		&& stack[!current_stack_index][1] < stack[!current_stack_index][3])
// 		return (1);
// 	if (current_stack_index
// 		&& array_biggest(stack[!current_stack_index] + 1, 3)
// 			== stack[!current_stack_index][2]
// 		&& stack[!current_stack_index][1] > stack[!current_stack_index][3])
// 		return (1);
// 	return (0);
// }

// int		*
// quick_sort_two(int **stack, int current_stack_index,
// 	size_t last_partition_len)
// {

// 	int		*best_sequence;

// 	best_sequence = best_two_sequence_return(
// 		(stack[current_stack_index][1] > stack[current_stack_index][2])
// 		+ is_sort_two_exception(stack, current_stack_index, last_partition_len),
// 		current_stack_index);
// 	return (best_sequence);
// }

// int
// is_sort_three_clean_exception(int **stack, int current_stack_index,
// 	size_t last_partition_len)
// {
// 	if (stack[current_stack_index][0] != 3 || last_partition_len > 6)
// 		return (1);
// 	if (last_partition_len != 6)
// 		return (0);
// 	return (!current_stack_index
// 		&& array_biggest(stack[current_stack_index] + 1, 3)
// 			== stack[current_stack_index][2]
// 		&& stack[current_stack_index][1] < stack[current_stack_index][3]
// 		&& (array_smallest(stack[!current_stack_index] + 1, 3)
// 			== stack[!current_stack_index][1]
// 		|| (array_smallest(stack[!current_stack_index] + 1, 3)
// 			== stack[!current_stack_index][2] &&
// 			stack[!current_stack_index][1] > stack[!current_stack_index][3])));
// 	return (current_stack_index
// 		&& array_smallest(stack[current_stack_index] + 1, 3)
// 			== stack[current_stack_index][2]
// 		&& stack[current_stack_index][1] > stack[current_stack_index][3]
// 		&& (array_biggest(stack[!current_stack_index] + 1, 3)
// 			== stack[!current_stack_index][1]
// 		|| (array_biggest(stack[!current_stack_index] + 1, 3)
// 			== stack[!current_stack_index][2] &&
// 			stack[!current_stack_index][1] < stack[!current_stack_index][3])));
// }

// int
// is_sort_three_clean_exception(int **stack, int current_stack_index,
// 	size_t last_partition_len)
// {
// 	if (stack[current_stack_index][0] != 3 || last_partition_len > 6)
// 		return (1);
// 	if (last_partition_len != 6)
// 		return (0);
// 	return (!current_stack_index
// 		&& array_biggest(stack[current_stack_index] + 1, 3)
// 			== stack[current_stack_index][2]
// 		&& stack[current_stack_index][1] < stack[current_stack_index][3]
// 		&& (array_smallest(stack[!current_stack_index] + 1, 3)
// 			== stack[!current_stack_index][1]
// 		|| (array_smallest(stack[!current_stack_index] + 1, 3)
// 			== stack[!current_stack_index][2] &&
// 			stack[!current_stack_index][1] > stack[!current_stack_index][3])));
// 	return (current_stack_index
// 		&& array_smallest(stack[current_stack_index] + 1, 3)
// 			== stack[current_stack_index][2]
// 		&& stack[current_stack_index][1] > stack[current_stack_index][3]
// 		&& (array_biggest(stack[!current_stack_index] + 1, 3)
// 			== stack[!current_stack_index][1]
// 		|| (array_biggest(stack[!current_stack_index] + 1, 3)
// 			== stack[!current_stack_index][2] &&
// 			stack[!current_stack_index][1] < stack[!current_stack_index][3])));
// }

// size_t
// quick_sort_three_clean(int **stack, int current_stack_index)
// {
// 	if ((array_biggest(stack[current_stack_index] + 1, 3)
// 			== stack[current_stack_index][1] && !current_stack_index)
// 		|| (array_smallest(stack[current_stack_index] + 1, 3)
// 			== stack[current_stack_index][1] && current_stack_index))
// 		return ((size_t)
// 			(RA * !current_stack_index + RB * current_stack_index));
// 	if ((array_biggest(stack[current_stack_index] + 1, 3)
// 			== stack[current_stack_index][2] && !current_stack_index)
// 		|| (array_smallest(stack[current_stack_index] + 1, 3)
// 			== stack[current_stack_index][2] && current_stack_index))
// 		return ((size_t)
// 			(RRA * !current_stack_index + RRB * current_stack_index));
// 	return ((size_t)(
// 		((stack[current_stack_index][1] > stack[current_stack_index][2]
// 			&& !current_stack_index)
// 		|| (stack[current_stack_index][1] < stack[current_stack_index][2]
// 			&& current_stack_index))
// 		* (SA * !current_stack_index + SB * current_stack_index)));
// }

// size_t
// quick_sort_three_crap(int **stack, int current_stack_index, int rotation_count)
// {
// 	if ((stack[current_stack_index][1] > stack[current_stack_index][2]
// 			&& !current_stack_index)
// 		|| (stack[current_stack_index][1] < stack[current_stack_index][2]
// 			&& current_stack_index))
// 		return ((size_t)(SA * !current_stack_index + SB * current_stack_index));
// 	if (!rotation_count && ((array_biggest(stack[current_stack_index] + 1, 3)
// 			== stack[current_stack_index][2] && !current_stack_index)
// 		|| (array_smallest(stack[current_stack_index] + 1, 3)
// 			== stack[current_stack_index][2] && current_stack_index)))
// 		return ((size_t)(RA * !current_stack_index + RB * current_stack_index));
// 	return (rotation_count
// 		* (size_t)(RRA * !current_stack_index + RRB * current_stack_index));
// }

// t_list		*
// quick_apply(t_quick_sort_loop_params *params, size_t instruction_index,
// 	int *rotation_count, t_list **instruction_subsequence)
// {
// 	t_list	*next_instruction;

// 	if (instruction_index == RA || instruction_index == RB)
// 		++*rotation_count;
// 	else if (instruction_index == RRA || instruction_index == RRB)
// 		--*rotation_count;
// 	if (!instruction_index)
// 		return (*instruction_subsequence);
// 	next_instruction = ft_lstnew((void *)instruction_index);
// 	if (!next_instruction)
// 	{
// 		quick_sort_exit(&params->quick_instruction_sequence);
// 		return (quick_sort_exit(instruction_subsequence));
// 	}
// 	(*params->instruction_array[instruction_index])(params->stack);
// 	(*instruction_subsequence)->content++;
// 	ft_lstadd_back(instruction_subsequence, next_instruction);
// 	debug_print_stack(params->stack, "quick_apply", params->debug_option,
// 		next_instruction);
// 	return (*instruction_subsequence);
// }

// t_list		*
// quick_sort_best_sequence(t_quick_sort_loop_params *params, size_t partition_len,
// 	int current_stack_index, size_t last_partition_len)
// {
// 	t_list	*instruction_subsequence;
// 	size_t	instruction_index;
// 	int		rotation_count;

// 	instruction_subsequence = ft_lstnew((void *)0);
// 	instruction_index = 1;
// 	rotation_count = 0;
// 	while (instruction_subsequence && instruction_index)
// 	{
// 		if (partition_len == 2)
// 			instruction_index = quick_sort_two(params->stack,
// 				current_stack_index,last_partition_len);
// 		else if (!is_sort_three_clean_exception(params->stack,
// 			current_stack_index, last_partition_len))
// 			instruction_index = quick_sort_three_clean(params->stack,
// 				current_stack_index);
// 		else
// 			instruction_index = quick_sort_three_crap(params->stack,
// 				current_stack_index, rotation_count);
// 		quick_apply(params, instruction_index, &rotation_count,
// 			&instruction_subsequence);
// 	}
// 	return (instruction_subsequence);
// }

static t_list	*
quick_sort_recursive_loop(t_quick_sort_loop_params *params,
	size_t partition_len, size_t last_partition_len)
{
	t_list		*instruction_subsequence;
	t_list		*tmp_instruction_subsequence;
	static int	current_stack_index;
	size_t		next_partition_len;

	next_partition_len = quick_sort_partitionning(params,
		current_stack_index, partition_len);
	if (next_partition_len)
	{
		instruction_subsequence = quick_sort_recursive_loop(params,
			partition_len - next_partition_len, partition_len);
		tmp_instruction_subsequence = quick_sort_recursive_loop(params,
			next_partition_len, partition_len);
		instruction_subsequence = instruction_sequence_merge(
			instruction_subsequence, tmp_instruction_subsequence);
		quick_apply(params, instruction_subsequence);
		instruction_sequence_concat(params->quick_instruction_sequence,
			instruction_subsequence);
		quick_partition_push_back(params, next_partition_len,
			current_stack_index);
		current_stack_index = !current_stack_index;
		return (NULL);
	}
	instruction_subsequence = quick_sort_best_sequence(params,
		partition_len, current_stack_index, last_partition_len);
	current_stack_index = !current_stack_index;
	return (instruction_subsequence);
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
		instruction_sequence_concat(quick_instruction_sequence,
			quick_sort_recursive_loop(&initial_params, stack[0][0],
				stack[0][0]));
		if (quick_instruction_sequence)
		{
			if (best_instruction_sequence->content
				< quick_instruction_sequence->content)
				{;}
				// return (quick_sort_exit(&quick_instruction_sequence));
		}
	}
	quick_push_cleanup(quick_instruction_sequence);
	return (quick_instruction_sequence);
}
