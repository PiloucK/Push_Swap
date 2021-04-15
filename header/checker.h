/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 15:16:07 by clkuznie          #+#    #+#             */
/*   Updated: 2021/04/15 20:42:07 by clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "libft.h"

typedef enum
        e_instructions
{
	PA = 1,
	PB,
	RRA,
	RRB,
	RRR,
	RA,
	RB,
	RR,
	SA,
	SB,
        SS,
}       t_instruction;

typedef void
        (*t_instruction_fnct)(int *stack[3]);

void	instruction_push_a(int *stack[3]);
void	instruction_push_b(int *stack[3]);
void	instruction_reverse_rotate_a(int *stack[3]);
void	instruction_reverse_rotate_b(int *stack[3]);
void	instruction_reverse_rotate_both(int *stack[3]);
void	instruction_rotate_a(int *stack[3]);
void	instruction_rotate_b(int *stack[3]);
void	instruction_rotate_both(int *stack[3]);
void	instruction_swap_a(int *stack[3]);
void	instruction_swap_b(int *stack[3]);
void	instruction_swap_both(int *stack[3]);

void	util_int_swap(int *a, int *b);
void	util_stack_rotate(int *stack);
void	util_stack_reverse_rotate(int *stack);

#endif
