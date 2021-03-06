/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_stack_reverse_rotate.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 15:59:39 by clkuznie          #+#    #+#             */
/*   Updated: 2021/04/30 20:30:11 by clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void
	util_stack_reverse_rotate(
	int *stack)
{
	int		i;

	if (stack[0] > 1)
	{
		i = stack[0] + 1;
		while (--i > 1)
			util_int_swap(&stack[i], &stack[i - 1]);
	}
}
