/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkoutrel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 14:02:03 by nkoutrel          #+#    #+#             */
/*   Updated: 2016/11/30 14:02:04 by nkoutrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_glist			*new_glist(size_t size, const int fd, int b)
{
	t_glist	*node;

	if (!(node = (t_glist *)malloc(sizeof(t_glist))))
		return (NULL);
	else
	{
		node->str = ft_strnew(size);
		node->i = 0;
		node->next = NULL;
		node->fd = fd;
		node->b = b;
		node->ret = -2;
		return (node);
	}
}

static int		loop_read(t_glist **list, char ***line)
{
	if ((*list)->buf[(*list)->b] != '\n')
	{
		(*list)->str[(*list)->i++] = (*list)->buf[(*list)->b++];
		if ((*list)->str[(*list)->i] == '\0')
			(*list)->str = ft_strdouble((*list)->str);
	}
	if ((*list)->buf[(*list)->b] == '\n')
	{
		(*list)->str[(*list)->i] = '\0';
		(*list)->b++;
		**line = (*list)->str;
		return (1);
	}
	return (0);
}

static int		end_read(t_glist **list, char ***line)
{
	if ((*list)->buf[(*list)->b] == '\0')
	{
		(*list)->b = 0;
		(*list)->ret = read((*list)->fd, (*list)->buf, BUFF_SIZE);
		(*list)->buf[(*list)->ret] = '\0';
		if ((*list)->ret == 0 && (*list)->i > 0)
		{
			(*list)->str[(*list)->i] = '\0';
			**line = (*list)->str;
			return (1);
		}
	}
	return (0);
}

int				get_next_line(const int fd, char **line)
{
	static t_glist		*list;

	if (fd < 0 || BUFF_SIZE <= 0)
		return (-1);
	if (list && list->buf[list->b])
	{
		list->str = ft_strnew(BUFF_SIZE);
		list->i = 0;
	}
	else
	{
		list = new_glist(BUFF_SIZE, fd, 0);
		list->ret = read(fd, list->buf, BUFF_SIZE);
		if (list->ret == -1)
			return (-1);
		list->buf[list->ret] = '\0';
	}
	while (list->ret != 0)
	{
		if (loop_read(&list, &line) == 1)
			return (1);
		if (end_read(&list, &line) == 1)
			return (1);
	}
	return (0);
}
