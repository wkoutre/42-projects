/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dig_counter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkoutrel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 09:54:01 by nkoutrel          #+#    #+#             */
/*   Updated: 2016/11/04 09:54:02 by nkoutrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_dig_counter(long int n, size_t base)
{
	size_t	num_digits;

	num_digits = 0;
	if (n < 0)
		num_digits++;
	while (n)
	{
		num_digits++;
		n /= (long int)base;
	}
	if (!num_digits)
		return (1);
	return (num_digits);
}
