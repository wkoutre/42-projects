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

/*
** Applies the function f to each character of the string passed as argument
** by giving its index as first argument to create a “fresh” new string
** (with malloc(3)) resulting from the suc- cessive applications of f.
*/

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
