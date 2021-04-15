/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 15:16:34 by clkuznie          #+#    #+#             */
/*   Updated: 2021/04/15 17:53:57 by clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int
error_print(int error)
{
	if (error)
		write(2, "Error\n", 7);
	return (error);
}

// int
// checker_close(void)
// {
// 	write(2, "Error\n", 7);
// 	return (1);
// }

// int
// checker_read(void)
// {
// 	char	read_buf[4];
// 	int		read_len;
	
// 	while (2)
// 	{
// 		read_len = read(0, read_buf, 3);
// 		if (read_len < 3)
// 			return (checker_close());
// 		else if ()
// 	}
// 	return (0)
// }

// int
// checker_params(char *stack[3], int stack_size, char **av)
// {
// }

void
print_existing_value(int *stack, int i)
{
	if (stack[0] >= i)
		ft_printf("%12d", stack[i]);
	else
		ft_printf("%12c", '.');
}

void
print_stack_column(int *stack[3], int stack_size)
{
	int		i;

	i = 0;
	ft_printf("%12d | %12d | %12d\n\n",
		stack[0][i], stack[1][i], stack[2][i]);
	while (++i <= stack_size)
	{
		print_existing_value(stack[0], i);
		ft_printf(" | ");
		print_existing_value(stack[1], i);
		ft_printf(" | ");
		print_existing_value(stack[2], i);
		ft_printf("\n");
	}
	ft_printf("\n%12s | %12s | %12s\n",
		"stack A", "stack B", "sorted stack");
}

void
stack_free(int *stack[3])
{
	free(stack[0]);
	stack[0] = NULL;
	free(stack[1]);
	stack[1] = NULL;
	free(stack[2]);
	stack[2] = NULL;
}

int
util_strict_atoi(const char *str, int *error)
{
	int		i;
	int		sign;
	int		total;

	sign = 1;
	total = 0;
	while (ft_iswspace(*str))
		++str;
	if ((*str == '-' && (sign = -1)) || *str == '+')
		++str;
	i = 0;
	while (ft_isdigit(str[i]))
	{
		if ((*error = (ft_isinflow(total, str[i] - '0', sign) != 1)))
			return (*error);
		total *= 10;
		total += str[i] - '0';
		i++;
	}
	if (str[i])
		*error = 1;
	return (total * sign);
}

int
stack_init_fill(int *stack[3], int stack_size, char **values)
{
	int		i;
	int		j;
	int		error;

	i = 0;
	error = 0;
	stack[0][0] = stack_size;
	stack[1][0] = 0;
	stack[2][0] = stack_size;
	while (!error && i++ < stack_size)
	{
		j = 0;
		stack[0][i] = util_strict_atoi(values[i], &error);
		stack[1][i] = 0;
		stack[2][i] = stack[0][i];
		while (++j < i && stack[0][i] != stack[0][j])
			;
		if (j != i)
			error = 1;
	}
	if (error)
		stack_free(stack);
	return (error_print(error));
}

int
stack_init_malloc(int *stack[3], int stack_size)
{
	stack[0] = NULL;
	stack[1] = NULL;
	stack[2] = NULL;
	stack[0] = malloc(sizeof(int) * stack_size + 1);
	if (stack[0])
		stack[1] = malloc(sizeof(int) * stack_size + 1);
	if (!stack[1])
		free(stack[0]);
	else
	{
		stack[2] = malloc(sizeof(int) * stack_size + 1);
		if (!stack[2])
			stack_free(stack);
	}
	return (error_print(!stack[0] || !stack[1] || !stack[2]));
}

void
stack_check_sort(int *stack)
{
	int		i;

	i = 1;
	while(i < stack[0] && stack[i] < stack[i + 1])
		i++;
	if (i == stack[0])
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}

void
instruction_fnct_index_error(int *stack[3])
{
	(void)stack;
	ft_printf("_instruction_fnct_index_error_\n");
	ft_printf("Should not go through here at anytime.\
Check where the instruction functions are called and what the index in\
function array was\n");
}

void
init_instruction_fnct_array(t_instruction_fnct fnct_array[256])
{
	int					i;

	i = 0;
	while (i < 256)
		fnct_array[i] = instruction_fnct_index_error;
	fnct_array[0] = instruction_push_a;
	fnct_array[1] = instruction_push_b;
	fnct_array[2] = instruction_reverse_rotate_a;
	fnct_array[3] = instruction_reverse_rotate_b;
	fnct_array[4] = instruction_reverse_rotate_both;
	fnct_array[5] = instruction_rotate_a;
	fnct_array[6] = instruction_rotate_b;
	fnct_array[7] = instruction_rotate_both;
	fnct_array[8] = instruction_swap_a;
	fnct_array[9] = instruction_swap_b;
	fnct_array[10] = instruction_swap_both;
}

int
main(int ac, char **av)
{
	int		*stack[3];
	// t_instruction_fnct	fnct_array[256];

	if (ac > 1)
	{
		if (stack_init_malloc(stack, ac - 1))
			return (1);
		if (stack_init_fill(stack, ac - 1, av))
			return (1);
		// checker_read_loop();
		stack_check_sort(stack[0]);
		print_stack_column(stack, ac - 1);
		stack_free(stack);
	}
	return (0);
}
