/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_sequence_merge.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 17:43:32 by clkuznie          #+#    #+#             */
/*   Updated: 2021/04/30 17:43:41 by clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*
instruction_sequence_merge(t_list *subsequence_a, t_list *subsequence_b)
{
	t_list	*longer_subsequence;
	t_list	*shorter_subsequence;

	instruction_merge_init(subsequence_a,
		subsequence_b, &longer_subsequence, &shorter_subsequence);
	if (!longer_subsequence)
		return (NULL);
	instruction_sequence_merge_loop(longer_subsequence->next, &shorter_subsequence);
	instruction_merge_finish(longer_subsequence, shorter_subsequence);
	longer_subsequence->content = (void *)(size_t)ft_lstsize(longer_subsequence->next);
	return (longer_subsequence);
}
