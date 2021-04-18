/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_swap_a.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 14:35:39 by clkuznie          #+#    #+#             */
/*   Updated: 2021/04/18 17:41:25 by clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void
instruction_swap_a(int *stack[3])
{
	if (stack[0][0] > 1)
		util_int_swap(&stack[0][1], &stack[0][2]);
}