/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_rotate_a.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 15:40:49 by clkuznie          #+#    #+#             */
/*   Updated: 2021/04/30 20:24:24 by clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int
	instruction_rotate_a(
	int *stack[4])
{
	util_stack_rotate(stack[0]);
	return (0);
}
