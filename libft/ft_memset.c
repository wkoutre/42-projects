/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkoutrel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 09:51:10 by nkoutrel          #+#    #+#             */
/*   Updated: 2016/11/02 09:51:17 by nkoutrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void					*ft_memset(void *str, int c, size_t n)
{
	size_t				i;
	unsigned char		*copy;

	i = 0;
	copy = str;
	if (n == 0)
		return (str);
	while (i < n)
	{
		copy[i] = (unsigned char)(c);
		i++;
	}
	return (str);
}
