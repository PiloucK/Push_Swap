/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_merge_init.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 17:41:09 by clkuznie          #+#    #+#             */
/*   Updated: 2021/04/30 17:41:20 by clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void
instruction_merge_init(t_list *subsequence_a, t_list *subsequence_b, t_list **longer_subsequence, t_list **shorter_subsequence)
{
	*longer_subsequence = NULL;
	*shorter_subsequence = NULL;
	if (subsequence_a && subsequence_b)
	{
		if ((size_t)subsequence_a->content > (size_t)subsequence_b->content
			|| (subsequence_a->content == subsequence_b->content && (size_t)subsequence_a->content > 0
			&& ((size_t)subsequence_a->next->content == SA || (size_t)subsequence_a->next->content == SB)))
		{
			*longer_subsequence = subsequence_a;
			*shorter_subsequence = subsequence_b->next;
			free(subsequence_b);
		}
		else
		{
			*longer_subsequence = subsequence_b;
			*shorter_subsequence = subsequence_a->next;
			free(subsequence_a);
		}
	}
	else if (subsequence_a)
		*longer_subsequence = subsequence_a;
	else
		*longer_subsequence = subsequence_b;
}
