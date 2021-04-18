/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_strict_atoi.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 16:40:32 by clkuznie          #+#    #+#             */
/*   Updated: 2021/04/18 17:43:39 by clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int
util_strict_atoi(const char *str, int *error)
{
	int					i;
	int					sign;
	int					total;

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
