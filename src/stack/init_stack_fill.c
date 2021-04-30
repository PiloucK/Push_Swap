/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack_fill.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 16:39:35 by clkuznie          #+#    #+#             */
/*   Updated: 2021/04/30 20:23:21 by clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int
	init_stack_fill(
	int *stack[4],
	int stack_size,
	char **values)
{
	int					i;
	int					j;
	int					error;

	i = 0;
	error = 0;
	stack[0][0] = stack_size;
	stack[1][0] = 0;
	stack[2][0] = stack_size;
	stack[3][0] = 0;
	while (!error && i++ < stack_size)
	{
		j = 0;
		stack[0][i] = util_strict_atoi(values[i], &error);
		stack[1][i] = 0;
		stack[2][i] = stack[0][i];
		stack[3][i] = 0;
		while (++j < i && stack[0][i] != stack[0][j])
			;
		if (j != i)
			error = 1;
	}
	if (error)
		stack_free(stack);
	return (print_error(error));
}
