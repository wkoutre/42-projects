#include "get_next_line.h"

/*
* ONE LEAK, ONE FAILED MOULINETTE TEST
* REMEMBER TO CHANGE HEADER FOR new_glist
*/

size_t 		ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (str)
	{
		while (*str)
		{
			i++;
			str++;
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
		while (i < size)
		{
			str[i++] = 1;
		}
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
	cpy = ft_strnew(len);
	if (cpy)
	{
		while (*str)
		{
			cpy[i++] = *str++;
		}
		cpy[len] = '\0';
		return (cpy);
	}
	return (NULL);
}

t_glist 	*new_glist(size_t size)
{
	t_glist	*node;

	if (!(node = (t_glist *)malloc(sizeof(t_glist))))
		return (NULL);
	else
	{
		node->str = ft_strnew(size);
		node->i = 0;
		node->next = NULL;
		return (node);
	}
}

int		read_loop(char **buf, int *b, const int fd, t_glist **list, int *ret)
{	
	if (*buf[*b] == '\n')
	{
		(*list)->str[(*list)->i] = '\0';
		(*b)++;
		/***line = *list->str;
		free(*list);*/
		return (1);
	}
	if (*buf[*b] == '\0')
	{
		*b = 0;
		*ret = read(fd, *buf, BUFF_SIZE);
		*buf[*ret] = '\0';
		if (*ret == 0 && (*list)->i > 0)
		{
			(*list)->str[(*list)->i] = '\0';
			*ret = 1;
			/***line = *list->str;*/
			return (1);
		}
	}
	return (0);
}

int			get_next_line(const int fd, char **line)
{
	t_glist		*list;
	int			ret;
	static int	b;
	static char	buf[BUFF_SIZE + 1];

	if (fd < 0 || BUFF_SIZE <= 0)
		return (-1);
	if (buf[b])
	{
		list = new_glist(BUFF_SIZE);
		while (buf[b])
		{
			if (buf[b] != '\n')
			{
				list->str[list->i++] = buf[b++];
				if (list->str[list->i] == '\0')
					list->str = ft_strdouble(list->str);
			}
			if (buf[b] == '\n')
			{
				list->str[list->i] = '\0';
				b++;
				*line = list->str;
				free(list);
				return (1);
			}
			if (buf[b] == '\0')
			{
				b = 0;
				ret = read(fd, buf, BUFF_SIZE);
				buf[ret] = '\0';
				if (ret == 0 && list->i > 0)
				{
					list->str[list->i] = '\0';
					*line = list->str;
					return (1);
				}
			}
		}
	}
	else
	{
		b = 0;
		list = new_glist(BUFF_SIZE);
		ret = read(fd, buf, BUFF_SIZE);
		if (ret == -1)
			return (-1);
		buf[ret] = '\0';
		while (ret != 0)
		{
			if (buf[b] != '\n')
			{
				list->str[list->i++] = buf[b++];
				if (list->str[list->i] == '\0')
					list->str = ft_strdouble(list->str);
			}
			if (buf[b] == '\n')
			{
				list->str[list->i] = '\0';
				b++;
				*line = list->str;
				free(list);
				return (1);
			}
			if (buf[b] == '\0')
			{
				b = 0;
				ret = read(fd, buf, BUFF_SIZE);
				buf[ret] = '\0';
				if (ret == 0 && list->i > 0)
				{
					list->str[list->i] = '\0';
					*line = list->str;
					return (1);
				}
			}
		}
	}
	return (0);
}

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
}*/


/*int		the_loop(char buf[][BUFF_SIZE + 1], int *b t_glist **list)
{
	while (*buf[*b])
	{
		if ((one_ret(&list, &b, &line, &buf) == 1))
			return (1);
		if (buf[*b] == '\0')
			if (test(&b, &list, &buf, &line) == 1)
				return (1);
	}
	return (0);
}
*/