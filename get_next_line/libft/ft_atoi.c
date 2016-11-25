/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkoutrel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/01 19:38:16 by nkoutrel          #+#    #+#             */
/*   Updated: 2016/11/01 19:38:17 by nkoutrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_atoi(const char *str)
{
	unsigned int	i;
	int				negative;
	int				result;

	i = 0;
	negative = 0;
	result = 0;
	while ((str[i] == '\n') || (str[i] == '\t') || (str[i] == '\v') ||
		(str[i] == ' ') || (str[i] == '\f') || (str[i] == '\r'))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			negative = 1;
		i++;
	}
	while ((str[i] >= '0') && (str[i] <= '9'))
	{
		result *= 10;
		result += (str[i] - '0');
		i++;
	}
	if (negative == 1)
		return (-result);
	return (result);
}
