/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clkuznie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 21:11:40 by clkuznie          #+#    #+#             */
/*   Updated: 2019/12/04 21:11:42 by clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_nbrlen(int n)
{
	int		len;

	len = 0;
	while (++len && (n /= 10))
		;
	return (len);
}
