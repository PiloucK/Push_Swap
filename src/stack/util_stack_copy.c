/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_stack_copy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 17:32:42 by clkuznie          #+#    #+#             */
/*   Updated: 2021/04/20 17:35:19 by clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void
util_stack_copy(int *destination_stack, int *source_stack)
{
	int		i;

	i = 0;
	if (destination_stack && source_stack)
	{
		while (i <= source_stack[0])
		{
			destination_stack[i] = source_stack[i];
			i++;
		}
	}
}
