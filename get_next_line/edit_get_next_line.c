#include "get_next_line.h"

char		read_char(char c)
{
	if (c != '\n')
		return (c);
	else
		return (0);
}

int			get_next_line(const int fd, char **line)
{
	t_glist		*list;
	int			ret;
	static char	buf[BUFF_SIZE + 1];
	int			i;
	static int	b;

	/*printf("GET NEXT LINE\n\n");
	printf("buf = %s\n", buf + b);*/
	i = 0;
	if (buf[b])
	{
		list = new_glist(BUFF_SIZE);
		while (buf[b])
		{
			if (buf[b] != '\n')
			{
				list->str[i++] = buf[b++];
				if (list->str[i] == '\0')
				{
					list->str = str_double(list->str);
				}
			}
			if (buf[b] == '\n')
			{
				list->str[i] = '\0';
				b++;
				*line = ft_strnew(ft_strlen(list->str));
				*line = list->str;
				/*printf("BOOP\n");*/
				return (1);
			}
			if (buf[b] == '\0')
			{
				b = 0;
				ret = read(fd, buf, BUFF_SIZE);
				buf[ret] = '\0';
			}
		}
	}
	else
	{
		b = 0;
		list = new_glist(BUFF_SIZE);
		ret = read(fd, buf, BUFF_SIZE);
		buf[ret] = '\0';
		while (/*buf[b] != 0 && buf[b] != '\n'*/ ret != 0)
		{
			/*printf("LOOP\n");*/
			if (buf[b] != '\n')
			{
				/*printf("BEFORE BUF[b] = %c\n", buf[b]);*/
				list->str[i++] = buf[b++];
				/*printf("STR = %s\n", list->str);*/
				/*printf("STR up top = %s\n", list->str);*/
				if (list->str[i] == '\0')
				{
					list->str = str_double(list->str);
					/*printf("STR DOUBLED = %s\n", list->str);*/
				}
				/*printf("AFTER IF\n");*/
			}
			/*printf("HOLD	\n");*/
			if (buf[b] == '\n')
			{
				/*printf("BUF NEW_LINE LOOP\n");*/
				list->str[i] = '\0';
				b++;
				/*printf("BUF NEW_LINE LOOP\n");*/
				*line = ft_strnew(ft_strlen(list->str));
				*line = list->str;
				return (1);
			}
			if (buf[b] == '\0')
			{
				/*printf("STR = %s\n", list->str);*/
				printf("here!!\n");
				b = 0;
				ret = read(fd, buf, BUFF_SIZE);
				buf[ret] = '\0';

				/*printf("STR = %s\n", list->str);*/
				/*printf("BELOW BUF[b] = %c\n", buf[b]);
				printf("BELOW BUF = %s\n", buf);*/
			}
		}
	}
	return (0);
}

int	main(int argc, char **argv)
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
	}
	return (0);
};

