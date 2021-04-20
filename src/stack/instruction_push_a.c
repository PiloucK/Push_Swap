/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_push_a.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 15:07:09 by clkuznie          #+#    #+#             */
/*   Updated: 2021/04/20 20:59:39 by clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void
instruction_push_a(int *stack[4])
{
	if (stack[1][0] > 0)
	{
		stack[0][++stack[0][0]] = stack[1][1];
		instruction_rotate_b(stack);
		instruction_reverse_rotate_a(stack);
		stack[1][0]--;
	}
}
