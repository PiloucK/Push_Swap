/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_read_loop.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 16:42:12 by clkuznie          #+#    #+#             */
/*   Updated: 2021/04/24 17:32:36 by clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int
checker_read_loop(int *stack[4], t_instruction_function instruction_array[256])
{
	char				read_buf[4];
	int					read_len;
	int					instruction_index;
	
	instruction_index = 1;
	while (instruction_index)
	{
		read_len = read(0, read_buf, 3);
		if (!read_len)
			return (0);
		if (read_len < 3)
			return (print_error(1));
		else if (read_buf[2] != '\n')
			read_len += read(0, &read_buf[3], 1);
		else
			read_buf[2] = '\0';
		if (read_len == 4 && read_buf[3] != '\n')
			return (print_error(1));
		read_buf[3] = '\0';
		instruction_index = checker_instruction_parse(read_buf);
		(*instruction_array[instruction_index])(stack);
	}
	return (0);
}
