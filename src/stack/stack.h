/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 17:35:59 by clkuznie          #+#    #+#             */
/*   Updated: 2021/04/18 17:36:15 by clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_HEADER_H
# define MAIN_HEADER_H

# include <stdlib.h>
# include <unistd.h>
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
        (*t_instruction_function)(int *stack[3]);

void	init_instruction_function_array(
	t_instruction_function instruction_array[256]);
int		init_stack_fill(int *stack[3], int stack_size, char **values);
int		init_stack_malloc(int *stack[3], int stack_size);

void	instruction_function_index_error(int *stack[3]);
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

int		print_error(int error);
void	print_existing_value(int *stack, int i);
void	print_stack_column(int *stack[3], int stack_size);

void	stack_check_sort(int *stack);
void	stack_free(int *stack[3]);

void	util_int_swap(int *a, int *b);
void	util_stack_rotate(int *stack);
void	util_stack_reverse_rotate(int *stack);
int		util_strict_atoi(const char *str, int *error);

#endif