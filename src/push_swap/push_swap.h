/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 16:08:20 by clkuznie          #+#    #+#             */
/*   Updated: 2021/04/18 22:51:37 by clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "stack.h"

void    sequence_elem_delete_function(void *data);
void    sort_apply(int *stack[3], t_instruction_function instruction_array[256],
	t_list **best_instruction_sequence);

#endif
