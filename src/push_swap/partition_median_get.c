/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   partition_median_get.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 17:43:52 by clkuznie          #+#    #+#             */
/*   Updated: 2021/04/30 17:43:59 by clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

float
partition_median_get(int *stack, long start_value, long partition_len)
{
	long	i;
	long	j;

	i = 0;
	while (stack[i + 1] != start_value)
		i++;
	j = 0;
	while (j < partition_len / 2)
		j++;
	if (partition_len % 2)
		return (stack[i + j + 1]);
	return (
		(stack[i + j] + stack[i + j + 1]) / 2.0
	);
}
