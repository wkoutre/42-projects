/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkoutrel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 20:36:15 by nkoutrel          #+#    #+#             */
/*   Updated: 2016/11/09 20:36:28 by nkoutrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (node)
	{
		if (content)
		{
			node->content_size = content_size;
			node->content = malloc(content_size);
			if (node->content)
				ft_memmove(node->content, content, content_size);
		}
		else
		{
			node->content_size = 0;
			node->content = malloc(0);
			node->content = NULL;
		}
		node->next = NULL;
	}
	return (node);
}
