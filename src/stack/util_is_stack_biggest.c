/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_is_stack_biggest.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 11:54:12 by clkuznie          #+#    #+#             */
/*   Updated: 2021/04/30 20:40:37 by clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int
	util_is_stack_biggest(
	int *stack[4],
	int current,
	int stack_to_scan)
{
	int		i;

	i = 1;
	while (i <= stack[stack_to_scan][0])
	{
		if (stack[stack_to_scan][i] > current)
			return (0);
		i++;
	}
	return (1);
}
