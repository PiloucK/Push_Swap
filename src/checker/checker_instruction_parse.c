/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_instruction_parse.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 16:46:09 by clkuznie          #+#    #+#             */
/*   Updated: 2021/04/30 20:40:59 by clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int
	checker_instruction_parse(
	char read_buf[4])
{
	return (
		!ft_strcmp(read_buf, "pa") * PA +
		!ft_strcmp(read_buf, "pb") * PB +
		!ft_strcmp(read_buf, "rra") * RRA +
		!ft_strcmp(read_buf, "rrb") * RRB +
		!ft_strcmp(read_buf, "rrr") * RRR +
		!ft_strcmp(read_buf, "ra") * RA +
		!ft_strcmp(read_buf, "rb") * RB +
		!ft_strcmp(read_buf, "rr") * RR +
		!ft_strcmp(read_buf, "sa") * SA +
		!ft_strcmp(read_buf, "sb") * SB +
		!ft_strcmp(read_buf, "ss") * SS);
}
