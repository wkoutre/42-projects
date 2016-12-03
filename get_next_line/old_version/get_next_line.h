#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <string.h>
# include "../libft/libft.h"

# define BUFF_SIZE 10

typedef struct		s_glist
{
	char 			*str;
	int				i;
	int				ret;
	int				fd;
	int				b;
	char			buf[BUFF_SIZE + 1];
	struct s_glist	*next;
	struct s_glist	*prev;
}					t_glist;

int			get_next_line(const int fd, char **line);
t_glist 	*new_glist(size_t size, const int fd, int b);

#endif