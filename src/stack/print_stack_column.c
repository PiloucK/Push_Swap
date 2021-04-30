/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stack_column.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 16:43:36 by clkuznie          #+#    #+#             */
/*   Updated: 2021/04/30 20:25:34 by clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void
	print_stack_column(
	int *stack[4])
{
	int					i;

	i = 0;
	ft_printf("\n\n%12d | %12d | %12d | %12d\n\n",
		stack[0][i], stack[1][i], stack[2][i], stack[3][i]);
	while (++i <= stack[2][0])
	{
		print_existing_value(stack[0], i);
		ft_printf(" | ");
		print_existing_value(stack[1], i);
		ft_printf(" | ");
		print_existing_value(stack[2], i);
		ft_printf(" | ");
		print_existing_value(stack[3], i);
		ft_printf("\n");
	}
	ft_printf("\n%12s | %12s | %12s | %12s\n",
		"stack A", "stack B", "base stack", "sorted stack");
}
