/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 17:44:45 by clkuznie          #+#    #+#             */
/*   Updated: 2021/04/30 19:17:04 by clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int
	array_is_ascending(
	int *array,
	size_t array_len)
{
	size_t	i;

	i = 0;
	while (i < array_len - 1)
	{
		if (array[i] > array[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int
	array_is_descending(
	int *array,
	size_t array_len)
{
	size_t	i;

	i = 0;
	while (i < array_len - 1)
	{
		if (array[i] < array[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int
	array_smallest(
	int *array,
	size_t array_len)
{
	size_t	i;
	int		smallest_value;

	i = 0;
	smallest_value = array[0];
	while (i != array_len)
	{
		if (array[i] < smallest_value)
			smallest_value = array[i];
		i++;
	}
	return (smallest_value);
}

int
	array_biggest(
	int *array,
	size_t array_len)
{
	size_t	i;
	int		biggest_value;

	i = 0;
	biggest_value = array[0];
	while (i != array_len)
	{
		if (array[i] > biggest_value)
			biggest_value = array[i];
		i++;
	}
	return (biggest_value);
}
