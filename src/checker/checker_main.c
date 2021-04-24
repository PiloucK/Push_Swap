/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 15:16:34 by clkuznie          #+#    #+#             */
/*   Updated: 2021/04/24 18:00:19 by clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int
main(int ac, char **av)
{
	int						*stack[4];
	t_instruction_function	instruction_array[256];

	if (ac > 1)
	{
		if (init_stack_malloc(stack, ac - 1))
			return (1);
		if (init_stack_fill(stack, ac - 1, av))
			return (1);
		init_instruction_function_array(instruction_array,
			instruction_function_index_error);
		if (!checker_read_loop(stack, instruction_array))
			checker_print_result(stack_is_sorted(stack[0]));
		print_stack_column(stack);
		stack_free(stack);
	}
	return (0);
}
