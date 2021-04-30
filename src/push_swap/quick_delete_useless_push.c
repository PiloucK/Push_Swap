/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_delete_useless_push.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 17:52:41 by clkuznie          #+#    #+#             */
/*   Updated: 2021/04/30 17:53:04 by clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void
    quick_delete_useless_push(t_list *quick_sort_best_sequence,
    t_list *first_push_b, t_list *valid_instruction, int push_to_skip)
{
	t_list	*last_valid_instruction;
	t_list	*to_delete;

	if (!quick_sort_best_sequence || !first_push_b)
		return ;
	while (push_to_skip-- > 0)
		first_push_b = first_push_b->next;
	last_valid_instruction = quick_sort_best_sequence;
	while (last_valid_instruction
        && last_valid_instruction->next != first_push_b)
		last_valid_instruction = last_valid_instruction->next;
	last_valid_instruction->next = valid_instruction;
	while (first_push_b && first_push_b != valid_instruction)
	{
		to_delete = first_push_b;
		first_push_b = first_push_b->next;
		free(to_delete);
	}
}
