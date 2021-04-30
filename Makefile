# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/05 14:09:03 by clkuznie          #+#    #+#              #
#    Updated: 2021/04/30 20:11:17 by clkuznie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	Push_Swap

STACK_SRCS		:= \
init_instruction_function_array \
init_stack_fill \
init_stack_malloc \
\
instruction_push_a \
instruction_push_b \
instruction_reverse_rotate_a \
instruction_reverse_rotate_b \
instruction_reverse_rotate_both \
instruction_rotate_a \
instruction_rotate_b \
instruction_rotate_both \
instruction_swap_a \
instruction_swap_b \
instruction_swap_both \
\
print_error \
print_existing_value \
print_stack_column \
\
stack_is_sorted \
stack_free \
stack_reset \
\
util_int_swap \
util_is_stack_biggest \
util_is_stack_smallest \
util_stack_copy \
util_stack_reverse_rotate \
util_stack_rotate \
util_strict_atoi

CHECKER_SRCS	:= \
checker_main \
\
checker_instruction_parse \
checker_print_result \
checker_read_loop \
instruction_function_index_error

PUSH_SWAP_SRCS	:= \
push_swap_main \
\
extraction_stack_sort \
\
array_test \
array_print_int \
find_best_case_index \
instruction_merge_init \
instruction_merge_insert \
instruction_merge_finish \
instruction_sequence_concat \
instruction_sequence_merge \
instruction_sequence_merge_loop \
partition_median_get \
quick_apply \
quick_delete_useless_push \
quick_partition_push \
quick_push_back \
quick_push_cleanup \
quick_sequence \
quick_sort_partitionning \
quick_sort_exit \
quick_sort_recursive_loop \
quick_sort_three \
quick_sort_two \
quick_stack_sort \
sequence_convert \
top_stack_sort \
top_stack_sort_a \
top_stack_sort_b \
\
debug_print_sequence \
debug_print_stack \
list_content_swap \
print_best_instruction_sequence \
sequence_elem_functions \
sort_apply \
sort_save_best

S				:= \
src/

O				:= \
obj/

I				:= \
-I lib/libft/ \
-I src/stack

L				:= \
lib/libft/libft.a

STACK_O			= \
$(addprefix $O, $(addsuffix .o, $(STACK_SRCS)))

CHECKER_O		= \
$(addprefix $O, $(addsuffix .o, $(CHECKER_SRCS)))

PUSH_SWAP_O		= \
$(addprefix $O, $(addsuffix .o, $(PUSH_SWAP_SRCS)))

C				:= gcc -g
CFLAGS			:= -Wall -Wextra -Werror
SANITIZE		:= -g3 -fsanitize=address

R				:= rm -f

$O%.o:			$Sstack/%.c src/stack/stack.h
	$C $(CFLAGS) $I -c $< -o $@

$O%.o:			$Schecker/%.c src/stack/stack.h src/checker/checker.h
	$C $(CFLAGS) $I -c $< -o $@

$O%.o:			$Spush_swap/%.c src/stack/stack.h src/push_swap/push_swap.h
	$C $(CFLAGS) $I -c $< -o $@

all:
	$(MAKE) -C lib/libft
	make $(NAME)

$(NAME):
	$(MAKE) checker
	$(MAKE) push_swap

checker:		$(STACK_O) $(CHECKER_O) $L
	$C $^ -o $@

push_swap:		$(STACK_O) $(PUSH_SWAP_O) $L
	$C $^ -o $@

clean:			cleanlib
	$R $(STACK_O) $(CHECKER_O) $(PUSH_SWAP_O)

fclean:			fcleanlib
	$R $(STACK_O) $(CHECKER_O) $(PUSH_SWAP_O)
	$R push_swap
	$R checker

cleanlib:
	make --directory=lib/libft clean

fcleanlib:
	make --directory=lib/libft fclean

norme:
	norminette *.c *.h

re:				fclean all

.PHONY: all bonus checker push_swap clean cleanlib fcleanlib libcomp norme re
