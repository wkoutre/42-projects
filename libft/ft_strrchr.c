/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkoutrel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 19:16:25 by nkoutrel          #+#    #+#             */
/*   Updated: 2016/11/03 19:16:33 by nkoutrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strrchr(const char *s, int c)
{
	char	*s_cpy;
	int		i;

	i = 0;
	c = (char)c;
	s_cpy = (char *)s;
	while (s_cpy[i])
		i++;
	if (s_cpy[i] == c)
		return (s_cpy + i);
	while (i > 0)
	{
		if (s_cpy[i] == c)
			return (s_cpy + i);
		i--;
	}
	if (s_cpy[i] == c)
		return (s_cpy + i);
	return (NULL);
}
