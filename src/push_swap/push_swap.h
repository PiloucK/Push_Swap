/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 16:08:20 by clkuznie          #+#    #+#             */
/*   Updated: 2021/04/22 15:12:26 by clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "stack.h"

# ifndef DEBUG_OPTION_STR
#  define DEBUG_OPTION_STR "-v"
# endif

typedef struct				s_quick_sort_loop_params
{
	int						**stack;
	t_instruction_function	*instruction_array;
	t_list					*quick_instruction_sequence;
	int						debug_option;
}							t_quick_sort_loop_params;

t_list	*extraction_stack_sort(int *stack[4],
	t_instruction_function instruction_array[256],
	t_list *best_instruction_sequence, int debug_option);
t_list	*quick_stack_sort(int *stack[4],
	t_instruction_function instruction_array[256],
	t_list *best_instruction_sequence, int debug_option);

void	debug_print_stack(int *stack[4], char *current_sort_name,
	int debug_option, t_list *last_instruction);
void	print_best_instruction_sequence(t_list *best_instruction_sequence);
void    sequence_elem_delete_function(void *data);
void	sequence_elem_print_function(void *elem_content);
void    sort_apply(int *stack[4], t_instruction_function instruction_array[256],
	t_list **best_instruction_sequence, int debug_option);
void	sort_save_best(t_list **best_instruction_sequence,
	t_list *instruction_sequence);

#endif
