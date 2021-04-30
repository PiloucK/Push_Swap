/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort_exit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 17:35:51 by clkuznie          #+#    #+#             */
/*   Updated: 2021/04/30 20:21:32 by clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list		*
	quick_sort_exit(
	t_quick_sort_loop_params *params)
{
	ft_lstclear(&params->quick_instruction_sequence,
		sequence_elem_delete_function);
	stack_free(params->stack_copy);
	return (NULL);
}
