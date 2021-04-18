/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_check_sort.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 16:38:32 by clkuznie          #+#    #+#             */
/*   Updated: 2021/04/18 17:42:50 by clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void
stack_check_sort(int *stack)
{
	int					i;

	i = 1;
	while(i < stack[0] && stack[i] < stack[i + 1])
		i++;
	if (i == stack[0])
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}
