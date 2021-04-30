/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort_three.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 17:50:48 by clkuznie          #+#    #+#             */
/*   Updated: 2021/04/30 19:50:13 by clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		*
	best_crap_sequence_return(
	int case_index,
	int current_stack_index)
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

	return (best_sequences[case_index + current_stack_index * 6]);
}

int		*
	best_clean_sequence_return(
	int case_index,
	int current_stack_index)
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

	return (best_sequences[case_index + current_stack_index * 6]);
}

int		*
	quick_sort_three(
	int **stack,
	int current_stack_index,
	size_t last_partition_len)
{
	int		opposite_index;
	int		case_index;

	case_index = find_best_case_index(stack, current_stack_index);
	if (stack[current_stack_index][0] != 3)
		return (best_crap_sequence_return(case_index, current_stack_index));
	if (last_partition_len != 6 || stack[!current_stack_index][0] == 3)
		return (best_clean_sequence_return(case_index, current_stack_index));
	opposite_index = find_best_case_index(stack, !current_stack_index);
	if ((case_index == 1 && (opposite_index == 4 || opposite_index < 2)
			&& !current_stack_index)
		|| (case_index == 4 && (opposite_index == 1 || opposite_index > 2)
			&& current_stack_index))
		return (best_crap_sequence_return(case_index, current_stack_index));
	return (best_clean_sequence_return(case_index, current_stack_index));
}
