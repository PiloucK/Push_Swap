/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_existing_value.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 16:44:35 by clkuznie          #+#    #+#             */
/*   Updated: 2021/04/18 17:42:22 by clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void
print_existing_value(int *stack, int i)
{
	if (stack[0] >= i)
		ft_printf("%12d", stack[i]);
	else
		ft_printf("%12c", '.');
}
