int		read_loop(char ***buf, int *b, const int fd, t_glist **list, int *ret)
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

// IN MAIN FUNCTION

if (read_loop(buf, &b, fd, &list, & ret) == 1)
{
	if (ret == 1)
		list->str[list->i] = '\0';
	*line = list->str;
	return (1);
}

int		is_newline(t_glist **list, int *b, char ***line)
{
	(*list)->str[(*list)->i] = '\0';
	(*b)++;
	**line = (*list)->str;
	free(*list);
	return (1);
}

int		is_null(int *b, int ret, t_glist **list, char ***line)
{
	*b = 0;
	if (ret == 0 && (*list)->i > 0)
	{
		(*list)->str[(*list)->i] = '\0';
		**line = (*list)->str;
		return (1);
	}
	else
		return (0);
}

int		end_ret(t_glist **list, char ***line)
{
	(*list)->str[(*list)->i] = '\0';
	**line = (*list)->str;
	return (1);
}