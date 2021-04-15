/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_stack_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 15:56:33 by clkuznie          #+#    #+#             */
/*   Updated: 2021/04/15 16:01:18 by clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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
