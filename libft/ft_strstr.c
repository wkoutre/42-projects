/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkoutrel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/01 19:47:33 by nkoutrel          #+#    #+#             */
/*   Updated: 2016/11/01 19:47:49 by nkoutrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	size_t	little_len;

	little_len = ft_strlen((char *)little);
	if (!(*little))
		return ((char *)big);
	while (*big)
	{
		if (*big == *little)
		{
			if (!(ft_strncmp(big, little, little_len)))
				return ((char *)big);
		}
		big++;
	}
	return (NULL);
}
