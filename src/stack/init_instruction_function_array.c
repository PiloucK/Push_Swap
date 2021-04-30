/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_instruction_function_array.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 16:32:46 by clkuznie          #+#    #+#             */
/*   Updated: 2021/04/30 20:23:03 by clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void
	init_instruction_function_array(
	t_instruction_function instruction_array[256],
	t_instruction_function default_instruction_function)
{
	int					i;

	i = 0;
	while (i < 256)
		instruction_array[i++] = default_instruction_function;
	instruction_array[PA] = instruction_push_a;
	instruction_array[PB] = instruction_push_b;
	instruction_array[RRA] = instruction_reverse_rotate_a;
	instruction_array[RRB] = instruction_reverse_rotate_b;
	instruction_array[RRR] = instruction_reverse_rotate_both;
	instruction_array[RA] = instruction_rotate_a;
	instruction_array[RB] = instruction_rotate_b;
	instruction_array[RR] = instruction_rotate_both;
	instruction_array[SA] = instruction_swap_a;
	instruction_array[SB] = instruction_swap_b;
	instruction_array[SS] = instruction_swap_both;
}
