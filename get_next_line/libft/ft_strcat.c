/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkoutrel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 11:40:48 by nkoutrel          #+#    #+#             */
/*   Updated: 2016/11/02 11:40:55 by nkoutrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	size_t	len;
	char	*copy;

	copy = ft_strlen(s1) + s1;
	len = ft_strlen((char *)s2) + 1;
	ft_memcpy(copy, s2, len);
	copy += len - 1;
	*copy = 0;
	return (s1);
}
