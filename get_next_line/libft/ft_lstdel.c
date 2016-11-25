/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkoutrel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 21:20:54 by nkoutrel          #+#    #+#             */
/*   Updated: 2016/11/09 21:21:02 by nkoutrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*iter;
	t_list	*prev;

	iter = *alst;
	while (iter)
	{
		del(iter->content, iter->content_size);
		prev = iter;
		iter = iter->next;
		ft_memdel((void **)(&prev));
	}
	*alst = NULL;
}
