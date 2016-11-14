/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkoutrel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 12:02:24 by nkoutrel          #+#    #+#             */
/*   Updated: 2016/11/02 12:02:34 by nkoutrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t	s2_len;
	char	*copy;

	copy = ft_strlen(s1) + s1;
	s2_len = ft_strlen((char *)s2);
	if (s2_len < n)
	{
		*(copy + s2_len) = 0;
		ft_memcpy(copy, s2, s2_len);
	}
	else
	{
		*(copy + n) = 0;
		ft_memcpy(copy, s2, n);
	}
	return (s1);
}
