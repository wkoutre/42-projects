#include "get_next_line.h"

size_t 		ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	if (str)
	{
		while (str[i])
		{
			i++;
		}
		return (i);
	}
	return (0);
}

char	*ft_strnew(size_t size)
{
	char 	*str;
	size_t	i;

	i = 0;
	str = (char *)malloc(sizeof(char) * (size + 1));
	if (str)
	{
		str[size] = '\0';
		return (str);
	}
	return (NULL);
}

char 		*ft_strdouble(char *str)
{
	char 	*cpy;
	int		i;
	size_t	len;

	i = 0;
	len = ft_strlen(str) * 2;
	cpy = str;
	if (!(str = ft_strnew(len)))
		return (NULL);
	while (cpy[i])
	{
		str[i] = cpy[i];
		i++;
	}
	str[len] = '\0';
	free(cpy);
	return (str);
}

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
		/*free(*list);*/
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

// MUST FREE MEMORY IN EXACT REVERSE ORDER OF HOW IT WAS ALLOCATED

/*int	main(int argc, char **argv)
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
	}
	return (0);
}
*/