/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_apply.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 17:51:57 by clkuznie          #+#    #+#             */
/*   Updated: 2021/04/30 20:06:11 by clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void
	quick_apply(
	t_quick_sort_loop_params *params,
	t_list *instruction_subsequence)
{
	if (!instruction_subsequence || !instruction_subsequence->content)
		return ;
	instruction_subsequence = instruction_subsequence->next;
	while (instruction_subsequence)
	{
		(*params->instruction_array[
			(size_t)instruction_subsequence->content])(params->stack);
		debug_print_stack(params->stack, "quick_apply", params->debug_option,
			instruction_subsequence);
		instruction_subsequence = instruction_subsequence->next;
	}
}
