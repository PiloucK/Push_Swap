
#include "push_swap.h"

int		*
best_clean_sequence_return(int sequence_index, int current_stack_index)
{
	static int	best_sequences[24][6] = {
		{0, 0, 0, 0, 0, 0}, {RA, RA, SA, RRA, RRA, 0},
		{RA, SA, RRA, 0, 0, 0}, {RRA, SA, 0, 0, 0, 0},
		{SA, RA, 0, 0, 0, 0}, {RA, SA, RRA, RRA, SA, 0},
        {SA, 0, 0, 0, 0, 0}, {SA, RA, RA, SA, RRA, RRA},
		{RA, RA, SA, RRA, 0, 0}, {RRA, 0, 0, 0, 0, 0},
		{SA, RA, SA, 0, 0, 0}, {RA, SA, RRA, RRA, 0, 0},
		{SA, RA, SA, RRA, 0, 0}, {SA, RRA, SA, 0, 0, 0},
		{SA, RA, SA, RRA, SA, 0}, {SA, RRA, 0, 0, 0, 0},
		{RA, RA, 0, 0, 0, 0}, {RA, RA, SA, 0, 0, 0},
		{RA, 0, 0, 0, 0, 0}, {RA, RA, SA, RRA, 0, 0},
		{RA, SA, 0, 0, 0, 0}, {RRA, SA, RA, 0, 0, 0},
        {SA, RA, RA, 0, 0, 0}, {SA, RA, RA, SA, 0, 0}
	};
	return (best_sequences[sequence_index + current_stack_index * 6]);
}

int		*
best_clean_sequence_return(int sequence_index, int current_stack_index)
{
	static int	best_sequences[24][6] = {

		{SB, RB, RB, SB, 0, 0}, {SB, RB, RB, 0, 0, 0},
        {RRB, SB, RB, 0, 0, 0}, {RB, SB, 0, 0, 0, 0},
        {RB, RB, SB, RRB, 0, 0}, {RB, 0, 0, 0, 0, 0},
		{RB, RB, SB, 0, 0, 0}, {RB, RB, 0, 0, 0, 0},
		{SB, RRB, 0, 0, 0, 0}, {SB, RB, SB, RRB, SB, 0},
		{SB, RRB, SB, 0, 0, 0}, {SB, RB, SB, RRB, 0, 0},
		{RB, SB, RRB, RRB, 0, 0}, {SB, RB, SB, 0, 0, 0},
		{RRB, 0, 0, 0, 0, 0}, {RB, RB, SB, RRB, 0, 0},
		{SB, RB, RB, SB, RRB, RRB}, {SB, 0, 0, 0, 0, 0},
		{RB, SB, RRB, RRB, SB, 0}, {SB, RB, 0, 0, 0, 0},
		{RRB, SB, 0, 0, 0, 0}, {RB, SB, RRB, 0, 0, 0},
		{RB, RB, SB, RRB, RRB, 0}, {0, 0, 0, 0, 0, 0}
	};
	return (best_sequences[sequence_index + current_stack_index * 6]);
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

    if (params)


	next_partition_len = partition_len / 2;
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
