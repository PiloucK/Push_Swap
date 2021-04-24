/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 16:47:37 by clkuznie          #+#    #+#             */
/*   Updated: 2021/04/24 17:56:46 by clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include <string.h>
#include <stdio.h>
#include <error.h>
#include <errno.h>

int
print_error(int error)
{
	if (error)
		write(2, "Error\n", 7);
	return (error);
}
