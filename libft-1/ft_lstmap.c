/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkoutrel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 21:47:44 by nkoutrel          #+#    #+#             */
/*   Updated: 2016/11/09 21:47:51 by nkoutrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new_list;
	t_list	*iter_old;
	t_list	*iter_new;

	if (lst)
	{
		new_list = f(lst);
		if (!(new_list))
			return (NULL);
		else
		{
			iter_old = lst->next;
			iter_new = new_list;
			while (iter_old)
			{
				iter_new->next = f(iter_old);
				iter_old = iter_old->next;
				iter_new = iter_new->next;
			}
		}
		return (new_list);
	}
	else
		return (NULL);
}
