/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sequence_elem_functions.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 19:53:07 by clkuznie          #+#    #+#             */
/*   Updated: 2021/04/20 15:30:49 by clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void
sequence_elem_print_function(void *elem_content)
{
	static char	*instruction_str[12] = {
		"ERROR",
		"pa", "pb", "rra", "rrb", "rrr", "ra", "rb", "rr", "sa", "sb", "ss"
	};
	ft_printf("%s\n", instruction_str[(long)elem_content]);
}

void
sequence_elem_delete_function(void *data)
{
	(void)data;
}
