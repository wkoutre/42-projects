/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_w_count.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkoutrel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 10:16:48 by nkoutrel          #+#    #+#             */
/*   Updated: 2016/11/04 10:16:56 by nkoutrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		w_count(const char *str, char c)
{
	int			count;
	int			prev;

	count = 0;
	prev = 0;
	while (*str)
	{
		if (*str == c && prev == 1)
			prev = 0;
		if (*str != c && prev == 0)
		{
			prev = 1;
			count++;
		}
		str++;
	}
	return (count);
}
