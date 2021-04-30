/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort_two.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 17:49:46 by clkuznie          #+#    #+#             */
/*   Updated: 2021/04/30 19:46:00 by clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		*
	best_two_sequence_return(
	int case_index,
	int current_stack_index)
{
	static int	best_sequences[6][5] = {
		{0, 0, 0, 0, 0},
		{SA, 0, 0, 0, 0},
		{RA, 0, 0, 0, 0},
		{0, 0, 0, 0, 0},
		{SB, 0, 0, 0, 0},
		{RB, 0, 0, 0, 0}
	};

	return (best_sequences[case_index + current_stack_index * 3]);
}

int		*
	quick_sort_two(
	int **stack,
	int current_stack_index)
{
	int		case_index;
	int		opposite_index;

	case_index = (!current_stack_index && stack[current_stack_index][1]
		> stack[current_stack_index][2])
			|| (current_stack_index && stack[current_stack_index][1]
		< stack[current_stack_index][2]);
	if (stack[!current_stack_index][0] != 3 || !case_index
		|| stack[current_stack_index][0] != 2)
		return (best_two_sequence_return(case_index, current_stack_index));
	opposite_index = find_best_case_index(stack, !current_stack_index);
	case_index += (opposite_index == 4 && current_stack_index)
		|| (opposite_index == 1 && !current_stack_index);
	return (best_two_sequence_return(case_index, current_stack_index));
}
