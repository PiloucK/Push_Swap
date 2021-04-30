/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_merge_insert.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 17:42:35 by clkuznie          #+#    #+#             */
/*   Updated: 2021/04/30 17:42:44 by clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void
instruction_merge_insert(t_list **longer_subsequence, t_list **shorter_subsequence)
{
	size_t	longer_remaining_instrucions_len; (void)longer_remaining_instrucions_len;
	size_t	shorter_remaining_instrucions_len; (void)shorter_remaining_instrucions_len;
	t_list	*tmp_instruction_save;	(void)tmp_instruction_save;
	t_list	*tmp_short_save;

	longer_remaining_instrucions_len = (size_t)ft_lstsize(*longer_subsequence);
	shorter_remaining_instrucions_len = (size_t)ft_lstsize(*shorter_subsequence);
	// ft_printf("long shit %u\n", longer_remaining_instrucions_len);
	// ft_printf("long shit %u\n", shorter_remaining_instrucions_len);
	if (longer_remaining_instrucions_len < shorter_remaining_instrucions_len
		|| (longer_remaining_instrucions_len == shorter_remaining_instrucions_len
		&& (size_t)(*shorter_subsequence)->content != RA
		&& (size_t)(*shorter_subsequence)->content != RB))
	{
		tmp_short_save = (*shorter_subsequence)->next;
		tmp_instruction_save = (*longer_subsequence)->next;
		list_content_swap(*longer_subsequence, *shorter_subsequence);
		(*longer_subsequence)->next = *shorter_subsequence;
		(*longer_subsequence)->next->next = tmp_instruction_save;
		*shorter_subsequence = tmp_short_save;
		*longer_subsequence = (*longer_subsequence)->next;
	}
	else
		*longer_subsequence = (*longer_subsequence)->next;
}
