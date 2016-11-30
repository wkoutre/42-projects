#include "get_next_line.h"

/*
* HAS ONE LEAK
* DOESN'T WORK WITH SOME BUFF_SIZES... not related to size, really
*/

t_glist 	*new_glist(size_t size, const int fd)
{
	t_glist	*node;

	if (!(node = (t_glist *)malloc(sizeof(t_glist))))
		return (NULL);
	else
	{
		node->str = ft_strnew(size);
		node->i = 0;
		node->next = NULL;
		node->ret = -2;
		node->fd = fd;
		return (node);
	}
}

int		one_ret(t_glist **list, int *b, char ***line, char buf[][BUFF_SIZE + 1])
{
	char 	*loc;

	loc = *buf;
	if (loc[*b] == '\n')
	{
		(*list)->str[(*list)->i] = '\0';
		**line = (*list)->str;
		(*b)++;
		return (1);
	}
	if (loc[*b] != '\n')
	{
		(*list)->str[(*list)->i++] = loc[*b];
		(*b)++;
		if ((*list)->str[(*list)->i] == '\0')
			(*list)->str = ft_strdouble((*list)->str);
	}
	return (0);
}

static int	finale(int *b, t_glist **list, char buf[][BUFF_SIZE + 1], char ***line)
{
	char	*str;

	*b = 0;
	(*list)->ret = read((*list)->fd, *buf, BUFF_SIZE);
	str = *buf;
	str[(*list)->ret] = '\0';
	*buf[BUFF_SIZE] = *str;
	if ((*list)->ret == 0 && (*list)->i > 0)
	{
		(*list)->str[(*list)->i] = '\0';
		**line = (*list)->str;
		return (1);
	}
	return (0);
}

int			get_next_line(const int fd, char **line)
{
	t_glist		*list;
	static int	b;
	static char	buf[BUFF_SIZE + 1];

	if (fd < 0 || BUFF_SIZE <= 0)
		return (-1);
	if (buf[b])
		list = new_glist(BUFF_SIZE, fd);
	else
	{
		b = 0;
		list = new_glist(BUFF_SIZE, fd);
		if ((list->ret = read(list->fd, buf, BUFF_SIZE)) == -1)
			return (-1);
		buf[list->ret] = '\0';
	}
	while (buf[b])
	{
		if ((one_ret(&list, &b, &line, &buf) == 1))
			return (1);
		if (buf[b] == '\0')
			if (finale(&b, &list, &buf, &line) == 1)
				return (1);
	}
	return (0);
}
/*
int	main(int argc, char **argv)
{
	int 	fd;
	char	*line;

	if (argc > 0)
	{
		fd = open(argv[1], O_RDONLY);
		while (get_next_line(fd, &line))
		{
			printf("LINE = %s\n", line);	
		}
		close(fd);
		return (0);
	}
	else	
		return (0);
}
*/