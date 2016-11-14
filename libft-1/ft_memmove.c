/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkoutrel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 11:06:36 by nkoutrel          #+#    #+#             */
/*   Updated: 2016/11/02 11:06:42 by nkoutrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*src_c;
	char	*dst_c;
	size_t	i;

	i = -1;
	src_c = (char *)src;
	dst_c = (char *)dst;
	if (src_c < dst_c)
		while ((int)(--len) >= 0)
			*(dst_c + len) = *(src_c + len);
	else
		while (++i < len)
			*(dst_c + i) = *(src_c + i);
	return (dst);
}
