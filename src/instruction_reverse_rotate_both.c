/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_reverse_rotate_both.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 16:14:01 by clkuznie          #+#    #+#             */
/*   Updated: 2021/04/15 16:14:14 by clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void
instruction_reverse_rotate_both(int *stack[3])
{
	util_stack_reverse_rotate(stack[0]);
	util_stack_reverse_rotate(stack[1]);
}
