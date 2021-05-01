NAME = push_swap_42

### CHECKER FILES

CHECK_DIR_C = src/checker/

CHECK_DIR_O = obj/checker/

CHECK_FILES_C = \
checker_main.c \
\
checker_instruction_parse.c \
checker_print_result.c \
checker_read_loop.c \
instruction_function_index_error.c


CHECK_FILES_O = $(addprefix $(CHECK_DIR_O), ${CHECK_FILES_C:c=o})

CHECK_EXE = checker

### PUSHSWAP FILES

PSWAP_DIR_C = src/push_swap/

PSWAP_DIR_O = obj/push_swap/

PSWAP_FILES_C = \
push_swap_main.c \
\
extraction_stack_sort.c \
\
array_test.c \
array_print_int.c \
find_best_case_index.c \
instruction_merge_init.c \
instruction_merge_insert.c \
instruction_merge_finish.c \
instruction_sequence_concat.c \
instruction_sequence_merge.c \
instruction_sequence_merge_loop.c \
partition_median_get.c \
quick_apply.c \
quick_delete_useless_push.c \
quick_partition_push.c \
quick_push_back.c \
quick_push_cleanup.c \
quick_sequence.c \
quick_sort_partitionning.c \
quick_sort_exit.c \
quick_sort_recursive_loop.c \
quick_sort_three.c \
quick_sort_two.c \
quick_stack_sort.c \
sequence_convert.c \
top_stack_sort.c \
top_stack_sort_a.c \
top_stack_sort_b.c \
\
debug_print_sequence.c \
debug_print_stack.c \
list_content_swap.c \
print_best_instruction_sequence.c \
sequence_elem_functions.c \
sort_apply.c \
sort_save_best.c

PSWAP_FILES_O = $(addprefix $(PSWAP_DIR_O), $(PSWAP_FILES_C:c=o))

PSWAP_EXE = push_swap

### STACK FILES

STACK_DIR_C = src/stack/

STACK_DIR_O = obj/stack/

STACK_FILES_C = \
init_instruction_function_array.c \
init_stack_fill.c \
init_stack_malloc.c \
\
instruction_push_a.c \
instruction_push_b.c \
instruction_reverse_rotate_a.c \
instruction_reverse_rotate_b.c \
instruction_reverse_rotate_both.c \
instruction_rotate_a.c \
instruction_rotate_b.c \
instruction_rotate_both.c \
instruction_swap_a.c \
instruction_swap_b.c \
instruction_swap_both.c \
\
print_error.c \
print_existing_value.c \
print_stack_column.c \
\
stack_is_sorted.c \
stack_free.c \
stack_reset.c \
\
util_int_swap.c \
util_is_stack_biggest.c \
util_is_stack_smallest.c \
util_stack_copy.c \
util_stack_reverse_rotate.c \
util_stack_rotate.c \
util_strict_atoi.c

STACK_FILES_O = $(addprefix $(STACK_DIR_O), $(STACK_FILES_C:c=o))

### GENERAL

H_FILE = src/push_swap/push_swap.h \
		src/checker/checker.h \
		src/stack/stack.h

I = -I src/stack/ \
	-I lib/libft/

LIBFT_DIR = lib/libft/

LIBFT = $(LIBFT_DIR)libft.a

CC = gcc

C_FLAGS = -Wall -Wextra -Werror $I

RM = rm -f

all: $(NAME)

$(NAME): lib_ft $(CHECK_EXE) $(PSWAP_EXE)

$(CHECK_EXE): $(CHECK_FILES_O) $(STACK_FILES_O) $(LIBFT)
	$(CC) $^ -o $@

$(CHECK_DIR_O)%.o: $(CHECK_DIR_C)%.c $(H_FILE)
	$(CC) $(C_FLAGS) -c $< -o $@

$(PSWAP_EXE): $(PSWAP_FILES_O) $(STACK_FILES_O) $(LIBFT)
	$(CC) $^ -o $@

$(PSWAP_DIR_O)%.o: $(PSWAP_DIR_C)%.c $(H_FILE)
	$(CC) $(C_FLAGS) -c $< -o $@

$(STACK_DIR_O)%.o: $(STACK_DIR_C)%.c $(H_FILE)
	$(CC) $(C_FLAGS) -c $< -o $@

lib_ft:
	make --directory=$(LIBFT_DIR)

clean:
	$(RM) $(CHECK_FILES_O)
	$(RM) $(PSWAP_FILES_O)
	$(RM) $(STACK_FILES_O)
	make --directory=$(LIBFT_DIR) clean

fclean: clean
	$(RM) $(CHECK_EXE)
	$(RM) $(PSWAP_EXE)
	$(RM) $(LIBFT)

re: fclean all

.PHONY: all bonus clean fclean re