/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 15:16:34 by clkuznie          #+#    #+#             */
/*   Updated: 2021/04/18 22:45:18 by clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int
main(int ac, char **av)
{
	int						*stack[3];
	t_instruction_function	instruction_array[256];

	if (ac > 1)
	{
		if (init_stack_malloc(stack, ac - 1))
			return (1);
		if (init_stack_fill(stack, ac - 1, av))
			return (1);
		init_instruction_function_array(instruction_array);
		checker_read_loop(stack, instruction_array);
		print_stack_column(stack, ac - 1);
		checker_print_result(stack_is_sorted(stack[0]));
		stack_free(stack);
	}
	return (0);
}
