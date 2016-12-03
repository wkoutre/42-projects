/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkoutrel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 19:26:08 by nkoutrel          #+#    #+#             */
/*   Updated: 2016/12/02 19:26:09 by nkoutrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char			*put_line(t_glist *list, char **line)
{
	char	*tmp;
	char	*copy;
	int		i;

	tmp = NULL;
	i = 0;
	copy = list->str;
	while (copy[i])
	{
		if (copy[i] == '\n')
		{
			*line = ft_strsub(copy, 0, i);
			tmp = copy;
			copy = ft_strdup(copy + (i + 1));
			free(tmp);
			return (copy);
		}
		i++;
	}
	*line = ft_strdup(copy);
	ft_strclr(copy);
	ft_strclr(list->str);
	return (copy);
}

static int			read_line(int fd, t_glist *list)
{
	char	*tmp;
	int		ret;
	char	buf[BUFF_SIZE + 1];

	tmp = NULL;
	ret = -2;
	while (!ft_strchr(list->str, '\n'))
	{
		if ((ret = read(fd, buf, BUFF_SIZE)) < 0)
			return (-1);
		else
		{
			buf[ret] = '\0';
			tmp = list->str;
			if (!(list->str = ft_strjoin(list->str, buf)))
				return (-1);
			free(tmp);
		}
		if (ret < BUFF_SIZE)
			return (ret);
	}
	return (ret);
}

static void			add_list(t_glist *list, t_glist *new)
{
	while (list)
	{
		if (list->next == NULL)
		{
			list->next = new;
			new->next = NULL;
		}
		list = list->next;
	}
}

static t_glist		*new_glist(const int fd)
{
	t_glist	*node;

	if (!(node = (t_glist *)malloc(sizeof(t_glist))))
		return (NULL);
	node->fd = fd;
	node->str = ft_strnew(0);
	node->next = NULL;
	return (node);
}

int					get_next_line(const int fd, char **line)
{
	static t_glist	*head;
	t_glist			*list;
	int				ret;

	if (!head)
		head = new_glist(fd);
	list = head;
	if (fd < 0 || !line)
		return (-1);
	while (list)
	{
		if (list->fd == fd)
			break ;
		if (list->next == NULL)
			add_list(list, new_glist(fd));
		list = list->next;
	}
	if ((ret = read_line(fd, list)) == -1)
		return (-1);
	list->str = put_line(list, line);
	if (!ft_strlen(list->str) && !ft_strlen(*line) && !ret)
		return (0);
	else
		return (1);
}
