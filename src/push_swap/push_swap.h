/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 16:08:20 by clkuznie          #+#    #+#             */
/*   Updated: 2021/04/30 23:54:28 by clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "stack.h"

# ifndef DEBUG_OPTION_STR
#  define DEBUG_OPTION_STR "-v"
# endif

# ifndef PARTITION_SIZE
#  define PARTITION_SIZE 3
# endif

typedef struct				s_quick_sort_loop_params
{
	int						**stack;
	t_instruction_function	*instruction_array;
	t_list					*quick_instruction_sequence;
	int						debug_option;
	int						*stack_copy[4];
}							t_quick_sort_loop_params;

t_list						*extraction_stack_sort(
	int *stack[4],
	t_instruction_function instruction_array[256],
	t_list *best_instruction_sequence,
	int debug_option);
t_list						*quick_stack_sort(
	int *stack[4],
	t_instruction_function instruction_array[256],
	t_list *best_instruction_sequence,
	int debug_option);

void						debug_print_sequence(
	t_list *sequence);
void						debug_print_stack(
	int *stack[4],
	char *current_sort_name,
	int debug_option,
	t_list *last_instruction);
void						list_content_swap(
	t_list *elem_a,
	t_list *elem_b);
void						print_best_instruction_sequence(
	t_list *best_instruction_sequence);
void						sequence_elem_debug_print(
	void *elem_content);
void						sequence_elem_delete_function(
	void *data);
void						sequence_elem_print_function(
	void *elem_content);
void						sort_apply(
	int *stack[4],
	t_instruction_function instruction_array[256],
	t_list **best_instruction_sequence,
	int debug_option);
void						sort_save_best(
	t_list **best_instruction_sequence,
	t_list *instruction_sequence);

int							array_biggest(
	int *array,
	size_t array_len);
int							array_is_ascending(
	int *array,
	size_t array_len);
int							array_is_descending(
	int *array,
	size_t array_len);
void						array_print_int(
	int *array,
	size_t array_len);
int							array_smallest(
	int *array,
	size_t array_len);
int							*best_clean_sequence_return(
	int case_index,
	int current_stack_index);
int							*best_crap_sequence_return(
	int case_index,
	int current_stack_index);
int							*best_two_sequence_return(
	int case_index,
	int current_stack_index);
int							find_best_case_index(
	int **stack,
	int current_stack_index);
void						instruction_merge_init(
	t_list *subsequence_a,
	t_list *subsequence_b,
	t_list **longer_subsequence,
	t_list **shorter_subsequence);
void						instruction_merge_insert(
	t_list **longer_subsequence,
	t_list **shorter_subsequence);
void						instruction_merge_finish(
	t_list *longer_subsequence,
	t_list *shorter_subsequence);
t_list						*instruction_sequence_concat(
	t_list *subsequence_a,
	t_list *subsequence_b);
t_list						*instruction_sequence_merge(
	t_list *subsequence_a,
	t_list *subsequence_b);
void						instruction_sequence_merge_loop(
	t_list *longer_subsequence,
	t_list **shorter_subsequence);
float						partition_median_get(
	int *stack,
	long start_value,
	long partition_len);
void						quick_apply(
	t_quick_sort_loop_params *params,
	t_list *instruction_subsequence);
void						quick_delete_useless_push(
	t_list *quick_sequence,
	t_list *first_push_b,
	t_list *valid_instruction,
	int push_to_skip);
t_list						*quick_partition_push(
	t_quick_sort_loop_params *params,
	int current_stack_index,
	float partition_median,
	size_t partition_len);
void						quick_push_back(
	t_quick_sort_loop_params *params,
	size_t pushed_len,
	int current_stack_index);
void						quick_push_cleanup(
	t_list *quick_sequence);
t_list						*quick_sequence(
	t_quick_sort_loop_params *params,
	size_t partition_len,
	int current_stack_index,
	size_t last_partition_len);
t_list						*quick_sort_exit(
	t_quick_sort_loop_params *params);
size_t						quick_sort_partitionning(
	t_quick_sort_loop_params *params,
	int current_stack_index,
	size_t partition_len);
t_list						*quick_sort_recursive_loop(
	t_quick_sort_loop_params *params,
	size_t partition_len,
	size_t last_partition_len);
int							*quick_sort_three(
	int **stack,
	int current_stack_index,
	size_t last_partition_len);
int							*quick_sort_two(
	int **stack,
	int current_stack_index);
t_list						*quick_stack_sort(
	int *stack[4],
	t_instruction_function instruction_array[256],
	t_list *best_instruction_sequence,
	int debug_option);
t_list						*sequence_convert(
	t_quick_sort_loop_params *params,
	int *best_sequence);
t_list						*top_stack_sort(
	t_quick_sort_loop_params *params,
	size_t partition_len,
	int current_stack_index);
t_list						*top_stack_sort_a(
	int **stack,
	int current_stack_index,
	size_t partition_len,
	t_list **top_instruction_sequence);
t_list						*top_stack_sort_b(
	int **stack,
	int current_stack_index,
	size_t partition_len,
	t_list **top_instruction_sequence);

#endif
