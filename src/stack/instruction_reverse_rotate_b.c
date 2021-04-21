/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_reverse_rotate_b.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 15:52:02 by clkuznie          #+#    #+#             */
/*   Updated: 2021/04/21 11:51:10 by clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int
instruction_reverse_rotate_b(int *stack[4])
{
	util_stack_reverse_rotate(stack[1]);
	return (0);
}
