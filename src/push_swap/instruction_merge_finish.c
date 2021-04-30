/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_merge_finish.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 17:41:43 by clkuznie          #+#    #+#             */
/*   Updated: 2021/04/30 19:39:54 by clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void
	instruction_merge_finish(
	t_list *longer_subsequence,
	t_list *shorter_subsequence)
{
	while (longer_subsequence && shorter_subsequence)
	{
		ft_lstadd_back(&longer_subsequence, shorter_subsequence);
		shorter_subsequence = shorter_subsequence->next;
	}
}
