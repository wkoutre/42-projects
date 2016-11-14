/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkoutrel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 13:59:42 by nkoutrel          #+#    #+#             */
/*   Updated: 2016/11/02 13:59:53 by nkoutrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		w_len(const char *str, int i, char c)
{
	while (str[i])
	{
		if (str[i] == c)
			break ;
		i++;
	}
	return (i);
}

static void		var_init(int *new_x, int *i, int *y)
{
	*new_x = 0;
	*y = 0;
	*i = 0;
}

static char		**end(char **a, int y)
{
	a[y] = 0;
	return (a);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**a;
	int		y;
	int		new_x;
	int		i;
	int		h;

	var_init(&new_x, &i, &y);
	if (!(s) || !(a = (char **)malloc(sizeof(char **) * (w_count(s, c) + 1))))
		return (NULL);
	while (s[i])
	{
		if (s[i] == c)
			i++;
		if (s[i] != c && s[i])
		{
			h = i;
			if (!(a[y] = (char *)malloc(sizeof(char *) * (w_len(s, i, c)) + 1)))
				return (NULL);
			while (h < (i = w_len(s, i, c)))
				a[y][new_x++] = s[h++];
			a[y++][new_x] = '\0';
			new_x = 0;
		}
	}
	return (end(a, y));
}
