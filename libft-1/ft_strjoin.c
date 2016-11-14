/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkoutrel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 09:02:45 by nkoutrel          #+#    #+#             */
/*   Updated: 2016/11/04 09:02:52 by nkoutrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*new_str;

	if (s1 && s2)
	{
		s1_len = ft_strlen((char *)s1);
		s2_len = ft_strlen((char *)s2);
		new_str = ft_strnew(s1_len + s2_len);
		if (new_str)
		{
			ft_memmove(new_str, s1, s1_len);
			ft_memmove(new_str + s1_len, s2, s2_len);
		}
		return (new_str);
	}
	else
		return (NULL);
}
