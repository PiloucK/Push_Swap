/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 16:08:01 by clkuznie          #+#    #+#             */
/*   Updated: 2021/04/19 17:03:18 by clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void
sequence_elem_print_function(void *elem_content)
{
	if ((long)elem_content == RA)
		ft_printf("ra\n");
	if ((long)elem_content == SA)
		ft_printf("sa\n");
}

void
print_best_instruction_sequence(t_list *best_instruction_sequence)
{
	if (best_instruction_sequence)
		ft_lstiter(best_instruction_sequence->next,
			sequence_elem_print_function);
}

int
main(int ac, char **av)
{
	int						*stack[3];
	t_instruction_function	instruction_array[256];
	t_list					*best_instruction_sequence;

	if (ac > 1)
	{
		if (init_stack_malloc(stack, ac - 1))
			return (1);
		if (init_stack_fill(stack, ac - 1, av))
			return (1);
		init_instruction_function_array(instruction_array);
		sort_apply(stack, instruction_array, &best_instruction_sequence);
		print_best_instruction_sequence(best_instruction_sequence);
		ft_lstclear(&best_instruction_sequence, sequence_elem_delete_function);
		stack_free(stack);
	}
	return (0);
}
