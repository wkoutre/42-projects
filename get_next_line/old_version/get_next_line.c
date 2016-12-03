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

/*
** This function keeps track of a SINGLE file descriptor, returning the next
** line of the file or input each time it is run WITHIN THE SAME PROGRAM.
** If the program ends, the thread will be lost and the first line will be
** assigned to "line" the next time "get_next_line" is called.
*/

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

/*
** The main loop for when the end of the buffer is not reached. Returns 1
** if a new line is reached. Otherwise, it iterates through the buffer.
*/

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

/*
** The function for when the end of a buffer is reached. If so, it reads
** the next part of the fd with # of bytes == BUFF_SIZE.
** IF there's nothing left to read ('read' returns 0 bytes) AND
** list->i > 0, this means the end of the file has been reached.
** This will only return 1 when the end of the file has been reached.
*/

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

/*
** The main function which sets the list correctly depending on if there is
** a pre-existing thread. If there is, it will start from that thread. If not,
** a new list will be created (new str allocation, new buffer, has fd == the
** parameter).
**
** NEED TO ADD: Reading from multiple file descriptors in the same program.
*/

int				get_next_line(const int fd, char **line)
{
	static t_glist		*list;

	if (fd < 0 || BUFF_SIZE <= 0 || line == NULL)
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
