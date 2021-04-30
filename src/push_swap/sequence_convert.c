/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sequence_convert.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 17:52:20 by clkuznie          #+#    #+#             */
/*   Updated: 2021/04/30 17:52:21 by clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list		*
sequence_convert(t_quick_sort_loop_params *params, int *best_sequence)
{
	t_list	*instruction_subsequence;
	t_list	*next_instruction;
	int		i;

	instruction_subsequence = ft_lstnew((void *)0);
	if (!instruction_subsequence)
		return (quick_sort_exit(params));
	i = 0;
	while (i < 5 && best_sequence[i])
	{
		instruction_subsequence->content++;
		next_instruction = ft_lstnew((void *)(size_t)best_sequence[i]);
		if (!instruction_subsequence)
		{
			ft_lstclear(&instruction_subsequence,
				sequence_elem_delete_function);
			return (quick_sort_exit(params));
		}
		ft_lstadd_back(&instruction_subsequence, next_instruction);
		i++;
	}
	return (instruction_subsequence);
}
