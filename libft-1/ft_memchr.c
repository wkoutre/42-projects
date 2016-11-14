/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkoutrel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 11:21:24 by nkoutrel          #+#    #+#             */
/*   Updated: 2016/11/02 11:21:32 by nkoutrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	t_byte	*s_ptr;

	s_ptr = (t_byte *)s;
	c = (t_byte)c;
	while (n)
	{
		if (*s_ptr == c)
			return (s_ptr);
		++s_ptr;
		--n;
	}
	return (NULL);
}
