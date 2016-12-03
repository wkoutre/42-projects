/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkoutrel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 20:45:36 by nkoutrel          #+#    #+#             */
/*   Updated: 2016/11/03 20:45:43 by nkoutrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Applies the function f to each character of the string given as argument to
** create a “fresh” new string (with malloc(3)) resulting from the successive
** applications of f.
*/

#include "libft.h"

char		*ft_strmap(char const *s, char (*f)(char))
{
	char	*new_str;
	char	*i;

	if (s)
	{
		new_str = ft_strdup(s);
		if (new_str)
		{
			i = new_str;
			while (*i)
			{
				*i = (*f)(*i);
				i++;
			}
		}
		return (new_str);
	}
	else
		return (NULL);
}
