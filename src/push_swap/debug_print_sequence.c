/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_print_sequence.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 17:36:21 by clkuznie          #+#    #+#             */
/*   Updated: 2021/04/30 17:58:26 by clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void
debug_print_sequence(t_list *sequence)
{
	char	interactive_tmp_buf[1];
	if (sequence)
	{
		ft_printf("len: %d sequence:", (int)(size_t)(sequence->content));
		ft_lstiter(sequence->next, sequence_elem_debug_print);
		write(1, "\n", 1);
	}
	read(0, interactive_tmp_buf, 1);
}
