/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_print_result.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 22:48:01 by clkuznie          #+#    #+#             */
/*   Updated: 2021/04/18 22:49:19 by clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void
checker_print_result(int is_correct)
{
	if (is_correct)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}
