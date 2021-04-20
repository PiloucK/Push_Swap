/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 16:41:16 by clkuznie          #+#    #+#             */
/*   Updated: 2021/04/20 21:27:41 by clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void
stack_free(int *stack[4])
{
	free(stack[0]);
	stack[0] = NULL;
	free(stack[1]);
	stack[1] = NULL;
	free(stack[2]);
	stack[2] = NULL;
	free(stack[3]);
	stack[3] = NULL;
}
