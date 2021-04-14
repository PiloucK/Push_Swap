/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 15:16:34 by clkuznie          #+#    #+#             */
/*   Updated: 2021/04/14 20:06:18 by clkuznie         ###   ########.fr       */
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
stack_column_print(int *stack[3], int stack_size)
{
	int		i;

	i = 0;
	ft_printf("%11d | %11d | %11d\n\n",
		stack[0][i], stack[1][i], stack[2][i]);
	while (++i <= stack_size)
		ft_printf("%11d | %11d | %11d\n",
			stack[0][i] * (stack[0][0] >= i),
			stack[1][i] * (stack[1][0] >= i),
			stack[2][i] * (stack[2][0] >= i));
	ft_printf("\n%11s | %11s | %11s\n",
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
		error = 0;
		stack[0][i] = ft_atoi(values[i]);
		stack[1][i] = 0;
		stack[2][i] = ft_atoi(values[i]);
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

int
main(int ac, char **av)
{
	int		*stack[3];

	if (ac > 1)
	{
		if (stack_init_malloc(stack, ac - 1))
			return (1);
		if (stack_init_fill(stack, ac - 1, av))
			return (1);
		stack_column_print(stack, ac - 1);
		// checker_params(stack, ac - 1, av + 1);
		// checker_read();
		stack_free(stack);
	}
	return (0);
}
