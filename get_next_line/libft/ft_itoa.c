/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkoutrel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/01 20:35:13 by nkoutrel          #+#    #+#             */
/*   Updated: 2016/11/01 20:35:26 by nkoutrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Allocate (with malloc(3)) and returns a “fresh” string end- ing with ’\0’
** representing the integer n given as argument. Negative numbers must be
** supported. If the allocation fails, the function returns NULL.
*/

#include "libft.h"

char		*ft_itoa(int n)
{
	size_t	digits;
	char	*num_string;
	char	*i;
	char	*dig_str;

	dig_str = "-0123456789";
	digits = ft_dig_counter(n, 10);
	num_string = ft_strnew(digits);
	if (num_string)
	{
		ft_memset(num_string, dig_str[1], digits);
		i = num_string + digits - 1;
		if (n < 0)
			*num_string = dig_str[0];
		while (n)
		{
			*i = dig_str[1 + (ft_abs(n) % 10)];
			i--;
			n /= (long int)10;
		}
	}
	return (num_string);
}
