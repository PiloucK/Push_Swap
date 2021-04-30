/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_merge_insert.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 17:42:35 by clkuznie          #+#    #+#             */
/*   Updated: 2021/04/30 20:07:48 by clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void
	instruction_merge_insert(
	t_list **long_subsequence,
	t_list **short_subsequence)
{
	size_t	long_remaining_instrucions_len;
	size_t	short_remaining_instrucions_len;
	t_list	*tmp_instruction_save;
	t_list	*tmp_short_save;

	long_remaining_instrucions_len = (size_t)ft_lstsize(*long_subsequence);
	short_remaining_instrucions_len = (size_t)ft_lstsize(*short_subsequence);
	if (long_remaining_instrucions_len < short_remaining_instrucions_len
		|| (long_remaining_instrucions_len == short_remaining_instrucions_len
		&& (size_t)(*short_subsequence)->content != RA
		&& (size_t)(*short_subsequence)->content != RB))
	{
		tmp_short_save = (*short_subsequence)->next;
		tmp_instruction_save = (*long_subsequence)->next;
		list_content_swap(*long_subsequence, *short_subsequence);
		(*long_subsequence)->next = *short_subsequence;
		(*long_subsequence)->next->next = tmp_instruction_save;
		*short_subsequence = tmp_short_save;
		*long_subsequence = (*long_subsequence)->next;
	}
	else
		*long_subsequence = (*long_subsequence)->next;
}
