/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_swap_both.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 15:05:22 by clkuznie          #+#    #+#             */
/*   Updated: 2021/04/15 15:05:50 by clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void
instruction_swap_both(int *stack[3])
{
	if (stack[0][0] > 1)
		util_int_swap(&stack[0][1], &stack[0][2]);
	if (stack[1][0] > 1)
		util_int_swap(&stack[1][1], &stack[1][2]);
}
