/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkoutrel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 11:26:22 by nkoutrel          #+#    #+#             */
/*   Updated: 2016/11/10 11:26:25 by nkoutrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memcpy(void *dest, const void *src, size_t n)
{
	t_byte	*a_ptr;
	t_byte	*b_ptr;

	a_ptr = (t_byte *)dest;
	b_ptr = (t_byte *)src;
	while (n)
	{
		*a_ptr = *b_ptr;
		++a_ptr;
		++b_ptr;
		--n;
	}
	return (dest);
}
