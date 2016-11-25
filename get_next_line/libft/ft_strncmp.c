/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkoutrel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/01 19:31:42 by nkoutrel          #+#    #+#             */
/*   Updated: 2016/11/01 19:31:46 by nkoutrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while (*s1 && *s2 && n != 0)
	{
		if ((t_byte)(*s1) - (t_byte)(*s2) != 0)
			return ((t_byte)(*s1) - (t_byte)(*s2));
		++s1;
		++s2;
		--n;
	}
	if (n)
		return ((t_byte)(*s1) - (t_byte)(*s2));
	return (0);
}
