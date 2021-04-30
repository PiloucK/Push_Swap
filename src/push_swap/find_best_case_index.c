/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_best_case_index.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 17:49:00 by clkuznie          #+#    #+#             */
/*   Updated: 2021/04/30 19:49:45 by clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int
	find_best_case_index(
	int **stack,
	int current_stack_index)
{
	int		i;

	i = !(stack[current_stack_index][1] < stack[current_stack_index][3]) * 3;
	if (!i)
		return (i
			+ (stack[current_stack_index][2] > stack[current_stack_index][3])
			+ ((stack[current_stack_index][2] < stack[current_stack_index][3])
			&& (stack[current_stack_index][1] > stack[current_stack_index][2]))
			* 2);
	else
		return (i
			+ (stack[current_stack_index][2] < stack[current_stack_index][3])
			+ ((stack[current_stack_index][1] > stack[current_stack_index][2])
			&& (stack[current_stack_index][2] > stack[current_stack_index][3]))
			* 2);
}
