/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_print_stack.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 15:42:04 by clkuznie          #+#    #+#             */
/*   Updated: 2021/04/30 23:25:32 by clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void
	debug_print_stack(
	int *stack[4],
	char *current_sort_name,
	int debug_option,
	t_list *last_instruction)
{
	char		interactive_tmp_buf[1];
	static int	skip_debug_print;
	int			read_return_value;

	if (debug_option && !skip_debug_print)
	{
		ft_printf("current algorithm = %s\n", current_sort_name);
		if (last_instruction)
		{
			ft_printf("applied instruction = ");
			write(1, "\x1b[1;36m", 8);
			sequence_elem_print_function(last_instruction->content);
			write(1, "\x1b[0m", 5);
		}
		print_stack_column(stack);
		read_return_value = read(0, interactive_tmp_buf, 1);
		if (read_return_value != 1)
			skip_debug_print = 1;
	}
	else
		skip_debug_print = 1;
}
