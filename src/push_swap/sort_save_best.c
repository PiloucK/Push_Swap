/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_save_best.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 10:40:32 by clkuznie          #+#    #+#             */
/*   Updated: 2021/04/20 17:45:36 by clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void
sort_save_best(t_list **best_instruction_sequence,
	t_list *instruction_sequence)
{
	if (instruction_sequence &&
		(long)(*best_instruction_sequence)->content
		> (long)instruction_sequence->content)
	{
		ft_lstclear(best_instruction_sequence, sequence_elem_delete_function);
		*best_instruction_sequence = instruction_sequence;
	}
	else
		ft_lstclear(&instruction_sequence);
}
