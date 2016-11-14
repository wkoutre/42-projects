/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkoutrel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 11:22:16 by nkoutrel          #+#    #+#             */
/*   Updated: 2016/11/10 11:22:18 by nkoutrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*special_case(const char *big, const char *little, size_t len)
{
	char	*ptr_big;
	char	*ptr_little;

	ptr_big = (char *)big;
	ptr_little = (char *)little;
	while (*ptr_big && len)
	{
		if (*ptr_little == 0)
			return (ptr_big - ft_strlen(little));
		if (*ptr_little == *ptr_big)
			ptr_little++;
		else
		{
			ptr_big -= ptr_little - (char *)little;
			len += ptr_little - (char *)little;
			ptr_little = (char *)little;
		}
		len--;
		ptr_big++;
	}
	if (*ptr_little == 0)
		return (ptr_big - ft_strlen(little));
	return (NULL);
}

char		*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t		i;
	const char	*s1_cpy;
	const char	*s2_cpy;
	size_t		len_cpy;

	s1_cpy = s1;
	s2_cpy = s2;
	len_cpy = len;
	if (*s2 == '\0')
		return ((char*)s1);
	i = 0;
	while (*s1 && len)
	{
		if (*s1 == s2[i])
			i++;
		else
			i = 0;
		if (s2[i] == '\0')
			return ((char *)(s1 - i + 1));
		s1++;
		len--;
	}
	return (special_case(s1_cpy, s2_cpy, len_cpy));
	return (NULL);
}
