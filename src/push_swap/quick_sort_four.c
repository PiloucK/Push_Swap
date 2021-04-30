/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort_four.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 17:54:21 by clkuznie          #+#    #+#             */
/*   Updated: 2021/04/30 17:54:22 by clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// int		*
// best_clean_sequence_return(int case_index, int current_stack_index)
// {
// 	static int	best_sequences[24][6] = {
// 		{0, 0, 0, 0, 0, 0}, {RA, RA, SA, RRA, RRA, 0},
// 		{RA, SA, RRA, 0, 0, 0}, {RRA, SA, 0, 0, 0, 0},
// 		{SA, RA, 0, 0, 0, 0}, {RA, SA, RRA, RRA, SA, 0},
//         {SA, 0, 0, 0, 0, 0}, {SA, RA, RA, SA, RRA, RRA},
// 		{RA, RA, SA, RRA, 0, 0}, {RRA, 0, 0, 0, 0, 0},
// 		{SA, RA, SA, 0, 0, 0}, {RA, SA, RRA, RRA, 0, 0},
// 		{SA, RA, SA, RRA, 0, 0}, {SA, RRA, SA, 0, 0, 0},
// 		{SA, RA, SA, RRA, SA, 0}, {SA, RRA, 0, 0, 0, 0},
// 		{RA, RA, 0, 0, 0, 0}, {RA, RA, SA, 0, 0, 0},
// 		{RA, 0, 0, 0, 0, 0}, {RA, RA, SA, RRA, 0, 0},
// 		{RA, SA, 0, 0, 0, 0}, {RRA, SA, RA, 0, 0, 0},
//         {SA, RA, RA, 0, 0, 0}, {SA, RA, RA, SA, 0, 0}
// 	};
// 	return (best_sequences[case_index]);
// }

// int		*
// best_clean_sequence_return(int case_index, int current_stack_index)
// {
// 	static int	best_sequences[24][6] = {

// 		{SB, RB, RB, SB, 0, 0}, {SB, RB, RB, 0, 0, 0},
//         {RRB, SB, RB, 0, 0, 0}, {RB, SB, 0, 0, 0, 0},
//         {RB, RB, SB, RRB, 0, 0}, {RB, 0, 0, 0, 0, 0},
// 		{RB, RB, SB, 0, 0, 0}, {RB, RB, 0, 0, 0, 0},
// 		{SB, RRB, 0, 0, 0, 0}, {SB, RB, SB, RRB, SB, 0},
// 		{SB, RRB, SB, 0, 0, 0}, {SB, RB, SB, RRB, 0, 0},
// 		{RB, SB, RRB, RRB, 0, 0}, {SB, RB, SB, 0, 0, 0},
// 		{RRB, 0, 0, 0, 0, 0}, {RB, RB, SB, RRB, 0, 0},
// 		{SB, RB, RB, SB, RRB, RRB}, {SB, 0, 0, 0, 0, 0},
// 		{RB, SB, RRB, RRB, SB, 0}, {SB, RB, 0, 0, 0, 0},
// 		{RRB, SB, 0, 0, 0, 0}, {RB, SB, RRB, 0, 0, 0},
// 		{RB, RB, SB, RRB, RRB, 0}, {0, 0, 0, 0, 0, 0}
// 	};
// 	return (best_sequences[case_index]);
// }
