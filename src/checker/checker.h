/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 15:16:07 by clkuznie          #+#    #+#             */
/*   Updated: 2021/04/18 17:01:04 by clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "stack.h"

int		checker_instruction_parse(char read_buf[4]);
void	checker_print_result(int is_correct);
int		checker_read_loop(int *stack[4],
	t_instruction_function instruction_array[256]);

#endif
