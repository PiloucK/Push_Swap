/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_print_int.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 17:44:16 by clkuznie          #+#    #+#             */
/*   Updated: 2021/04/30 19:37:23 by clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void
	array_print_int(
	int *array,
	size_t array_len)
{
	size_t	i;

	i = 0;
	write(1, "| ", 2);
	while (i < array_len)
	{
		ft_printf("%d |", array[i]);
		i++;
	}
	write(1, "\n", 1);
}
