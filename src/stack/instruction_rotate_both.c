/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_rotate_both.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 16:13:12 by clkuznie          #+#    #+#             */
/*   Updated: 2021/04/30 20:24:47 by clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int
	instruction_rotate_both(
	int *stack[4])
{
	util_stack_rotate(stack[0]);
	util_stack_rotate(stack[1]);
	return (0);
}
