/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkoutrel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 20:58:49 by nkoutrel          #+#    #+#             */
/*   Updated: 2016/11/03 20:58:56 by nkoutrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*new_str;
	char			*i;
	unsigned int	index;

	if (s)
	{
		new_str = ft_strdup(s);
		index = 0;
		if (new_str)
		{
			i = new_str;
			while (*i)
			{
				*i = (*f)(index, *i);
				i++;
				index++;
			}
		}
		return (new_str);
	}
	else
		return (NULL);
}
