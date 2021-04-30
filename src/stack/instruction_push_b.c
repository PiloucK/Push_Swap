/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_push_b.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 15:13:02 by clkuznie          #+#    #+#             */
/*   Updated: 2021/04/30 20:13:03 by clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int
	instruction_push_b(
	int *stack[4])
{
	if (stack[0][0] > 0)
	{
		stack[1][++stack[1][0]] = stack[0][1];
		instruction_rotate_a(stack);
		instruction_reverse_rotate_b(stack);
		stack[0][0]--;
	}
	return (0);
}
