/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_reverse_rotate_b.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 15:52:02 by clkuznie          #+#    #+#             */
/*   Updated: 2021/04/15 16:01:03 by clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void
instruction_reverse_rotate_b(int *stack[3])
{
	util_stack_reverse_rotate(stack[1]);
}
