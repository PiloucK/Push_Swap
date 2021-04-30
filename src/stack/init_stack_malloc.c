/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack_malloc.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 16:37:37 by clkuznie          #+#    #+#             */
/*   Updated: 2021/04/30 20:23:34 by clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int
	init_stack_malloc(
	int *stack[4],
	int stack_size)
{
	stack[0] = NULL;
	stack[1] = NULL;
	stack[2] = NULL;
	stack[0] = malloc(sizeof(**stack) * (stack_size + 1));
	if (stack[0])
		stack[1] = malloc(sizeof(**stack) * (stack_size + 1));
	if (!stack[1])
		free(stack[0]);
	else
	{
		stack[2] = malloc(sizeof(**stack) * (stack_size + 1));
		if (!stack[2])
			stack_free(stack);
	}
	if (stack[0] && stack[1] && stack[2])
		stack[3] = malloc(sizeof(**stack) * (stack_size + 1));
	if (!stack[3])
		stack_free(stack);
	return (print_error(!stack[0] || !stack[1] || !stack[2] || !stack[3]));
}
