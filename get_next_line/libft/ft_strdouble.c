/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdouble.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkoutrel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 21:27:29 by nkoutrel          #+#    #+#             */
/*   Updated: 2016/11/29 21:27:30 by nkoutrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdouble(char *str)
{
	char	*cpy;
	int		i;
	size_t	len;

	i = 0;
	len = ft_strlen(str) * 2;
	cpy = str;
	if (!(str = ft_strnew(len)))
		return (NULL);
	while (cpy[i])
	{
		str[i] = cpy[i];
		i++;
	}
	str[len] = '\0';
	free(cpy);
	return (str);
}
