/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_print_result.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 22:48:01 by clkuznie          #+#    #+#             */
/*   Updated: 2021/04/30 23:19:21 by clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void
	checker_print_result(
	int is_correct)
{
	if (is_correct)
	{
		write(1, "\x1b[1;32m", 8);
		ft_printf("OK\n");
		write(1, "\x1b[0m", 5);
	}
	else
	{
		write(1, "\x1b[1;31m", 8);
		ft_printf("KO\n");
		write(1, "\x1b[0m", 5);
	}
}
