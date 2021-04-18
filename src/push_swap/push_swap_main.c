/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 16:08:01 by clkuznie          #+#    #+#             */
/*   Updated: 2021/04/18 16:50:09 by clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int
main(int ac, char **av)
{
	int					*stack[3];
	t_instruction_function	instruction_array[256];

	if (ac > 1)
	{
		if (init_stack_malloc(stack, ac - 1))
			return (1);
		if (init_stack_fill(stack, ac - 1, av))
			return (1);
		init_instruction_function_array(instruction_array);
		stack_check_sort(stack[0]);
		ft_printf("push_swap\n");
		stack_free(stack);
	}
	return (0);
}
