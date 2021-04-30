/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 16:08:01 by clkuznie          #+#    #+#             */
/*   Updated: 2021/04/30 20:04:34 by clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int
	default_function(
	int *stack[4])
{
	(void)stack;
	return (1);
}

int
	util_is_debug_option(
	char *option_str)
{
	return (!ft_strcmp(option_str, DEBUG_OPTION_STR));
}

int
	main(
	int ac,
	char **av)
{
	int						*stack[4];
	t_instruction_function	instruction_array[256];
	t_list					*best_instruction_sequence;
	int						debug_option;

	if (ac > 1)
	{
		debug_option = util_is_debug_option(av[1]);
		if (debug_option)
		{
			ac--;
			av++;
		}
		if (init_stack_malloc(stack, ac - 1))
			return (1);
		if (init_stack_fill(stack, ac - 1, av))
			return (1);
		init_instruction_function_array(instruction_array, default_function);
		sort_apply(stack, instruction_array, &best_instruction_sequence,
			debug_option);
		print_best_instruction_sequence(best_instruction_sequence);
		ft_lstclear(&best_instruction_sequence, sequence_elem_delete_function);
		stack_free(stack);
	}
	return (0);
}
