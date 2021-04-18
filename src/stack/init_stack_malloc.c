/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack_malloc.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 16:37:37 by clkuznie          #+#    #+#             */
/*   Updated: 2021/04/18 17:39:38 by clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int
init_stack_malloc(int *stack[3], int stack_size)
{
	stack[0] = NULL;
	stack[1] = NULL;
	stack[2] = NULL;
	stack[0] = malloc(sizeof(int) * stack_size + 1);
	if (stack[0])
		stack[1] = malloc(sizeof(int) * stack_size + 1);
	if (!stack[1])
		free(stack[0]);
	else
	{
		stack[2] = malloc(sizeof(int) * stack_size + 1);
		if (!stack[2])
			stack_free(stack);
	}
	return (print_error(!stack[0] || !stack[1] || !stack[2]));
}
