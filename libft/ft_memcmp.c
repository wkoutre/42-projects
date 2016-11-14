/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkoutrel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 11:26:52 by nkoutrel          #+#    #+#             */
/*   Updated: 2016/11/02 11:26:59 by nkoutrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	t_byte	*s1_ptr;
	t_byte	*s2_ptr;

	s1_ptr = (t_byte *)s1;
	s2_ptr = (t_byte *)s2;
	while (n)
	{
		if (*s1_ptr != *s2_ptr)
			return (*s1_ptr - *s2_ptr);
		++s1_ptr;
		++s2_ptr;
		--n;
	}
	return (0);
}
