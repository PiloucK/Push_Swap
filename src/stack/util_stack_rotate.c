/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_stack_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 15:56:33 by clkuznie          #+#    #+#             */
/*   Updated: 2021/04/18 17:43:26 by clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void
util_stack_rotate(int *stack)
{
	int		i;

	if (stack[0] > 1)
	{
		i = 0;
		while (++i < stack[0])
			util_int_swap(&stack[i], &stack[i + 1]);
	}
}
