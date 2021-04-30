/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_is_sorted.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 16:38:32 by clkuznie          #+#    #+#             */
/*   Updated: 2021/04/30 20:40:08 by clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int
	stack_is_sorted(
	int *stack)
{
	int					i;

	i = 1;
	while (i < stack[0] && stack[i] < stack[i + 1])
		i++;
	if (i == stack[0])
		return (1);
	else
		return (0);
}
