#include "get_next_line.h"

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
		return (0);
	}
	else	
		return (0);
}
