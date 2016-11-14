/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkoutrel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 10:59:04 by nkoutrel          #+#    #+#             */
/*   Updated: 2016/11/02 10:59:10 by nkoutrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	t_byte	*a_ptr;
	t_byte	*b_ptr;

	a_ptr = (t_byte *)dest;
	b_ptr = (t_byte *)src;
	c = (t_byte)(c);
	while (n)
	{
		*a_ptr = *b_ptr;
		++a_ptr;
		if (*b_ptr == c)
			return (a_ptr);
		++b_ptr;
		--n;
	}
	return (NULL);
}
