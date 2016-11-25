#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <string.h>

# define BUFF_SIZE 10

typedef struct		s_glist
{
	char 			*str;
	int				i;
	int				ret;
	int				fd;
	char			buf[BUFF_SIZE + 1];
	struct s_glist	*next;
}					t_glist;

int			get_next_line(const int fd, char **line);

t_glist 	*new_glist(size_t size, const int fd);

int			ft_isnewline(char c);

size_t 		ft_strlen(char *str);

char		*ft_strnew(size_t size);
char 		*str_double(char *str);

/*size_t 		ft_strlen(char *str)
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
			str[i++] = 0;
		}
		str[size] = '\0';
		return (str);
	}
	return (NULL);
}

char 		*str_double(char *str)
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

int			ft_isnewline(char c)
{
	if (c == '\n')
		return (1);
	else
		return (0);
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
}*/

#endif