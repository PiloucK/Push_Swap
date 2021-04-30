/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_best_instruction_sequence.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 10:31:37 by clkuznie          #+#    #+#             */
/*   Updated: 2021/04/30 19:42:14 by clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void
	print_best_instruction_sequence(
	t_list *best_instruction_sequence)
{
	if (best_instruction_sequence)
		ft_lstiter(best_instruction_sequence->next,
			sequence_elem_print_function);
}
