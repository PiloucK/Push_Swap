/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_sequence_concat.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 17:40:32 by clkuznie          #+#    #+#             */
/*   Updated: 2021/04/30 17:40:43 by clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*
instruction_sequence_concat(t_list *subsequence_a, t_list *subsequence_b)
{
	if (!subsequence_a || !subsequence_b)
	{
		if (subsequence_a)
			return (subsequence_a);
		else if (subsequence_b)
			return (subsequence_b);
		return (NULL);
	}
	ft_lstadd_back(&subsequence_a, subsequence_b->next);
	subsequence_a->content = (void *)((long)subsequence_a->content
		+ (long)subsequence_b->content);
	free(subsequence_b);
	return (subsequence_a);
}
