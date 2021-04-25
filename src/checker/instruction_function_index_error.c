/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_function_index_error.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 17:23:20 by clkuznie          #+#    #+#             */
/*   Updated: 2021/04/25 17:02:54 by clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int
instruction_function_index_error(int *stack[4])
{
	(void)stack;
	write(1, "Error\n", 7);
	return (0);
}
