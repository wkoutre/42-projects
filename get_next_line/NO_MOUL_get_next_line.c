#include "get_next_line.h"

/*
* REMEMBER TO CHANGE T_GLIST IN HEADER FILE
* DOESN'T WORK WITH MOULINETTE TEST
*/

t_glist 	*new_glist(size_t size, const int fd, int b)
{
	t_glist	*node;

	if (!(node = (t_glist *)malloc(sizeof(t_glist))))
		return (NULL);
	else
	{
		node->str = ft_strnew(size);
		node->i = 0;
		node->b = b;
		node->next = NULL;
		node->ret = -2;
		node->fd = fd;
		return (node);
	}
}

int	get_next_line(const int fd, char **line)
{
	static t_glist		*list;

	if (list && list->buf[list->b])
	{
		/*printf("UPPER\n");
		printf("buf[b] = %c\n", list->buf[list->b]);*/
		while (list->ret > 0)
		{
			if (list->buf[list->b] == '\n')
			{
				/*printf("new line buf[b] = %c\n", list->buf[list->b]);*/
				list->str[list->i] = '\0';
				*line = list->str;
				(list->b)++;
				list->i = 0;
				return (1);
			}
			if (list->buf[list->b] != '\n')
			{
/*				printf("buf[b] = %c\n", list->buf[list->b]);*/
				list->str[list->i++] = list->buf[list->b++];
				if (list->str[list->i] == '\0')
					list->str = ft_strdouble(list->str);
			}
			if (list->buf[list->b] == '\0')
			{
				if ((list->ret = read(list->fd, list->buf, BUFF_SIZE)) == 0 && list->i > 0)
				{
					list->str[list->i] = '\0';
					*line = list->str;
					return (1);
					printf("END_FILE\n");
				}
				if (list->ret == -1)
					return (-1);
				/*printf("buf[b] down here= %c\n", list->buf[list->b]);*/
				list->b = 0;
				list->buf[list->ret] = '\0';
				/*printf("i = %d\n", list->i);
				printf("list->ret = %d\n", list->ret);*/
			}
		}
	}
	else
	{
		/*printf("LOWER\n");*/
		if (!(list = new_glist(BUFF_SIZE, fd, 0)))
			return (-1);
		while ((list->ret = read(list->fd, list->buf, BUFF_SIZE)) != 0)
		{
			if (list->ret == -1)
				return (-1);
			while (list->buf[list->b])
			{
				list->buf[list->ret] = '\0';
				if (list->buf[list->b] == '\n')
				{
					list->str[list->i] = '\0';
					*line = list->str;
					list->b++;
					list->i = 0;
					return (1);
				}
				if (list->buf[list->b] != '\n')
				{
					list->str[list->i++] = list->buf[list->b++];
					if (list->str[list->i] == '\0')
						list->str = ft_strdouble(list->str);
				}
				if (list->buf[list->b] == '\0')
				{
					if ((list->ret = read(list->fd, list->buf, BUFF_SIZE)) == 0 && list->i > 0)
					{
						list->str[list->i] = '\0';
						*line = list->str;
						return (1);
					}
					if (list->ret == -1)
						return (-1);
					list->b = 0;
					list->buf[list->ret] = '\0';
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

	if (argc > 1)
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