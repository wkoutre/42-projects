#include "get_next_line.h"

int	main(int argc, char **argv)
{
	int 	fd;
	char	*line;
	int 	ret;

	(void)argc;
	fd = open(argv[1], O_RDONLY);
	/*printf("return = %d\n", get_next_line(fd, &line));
	printf("LINE = %s\n", line);
	return (0);*/
	while (1)
	{
		ret = get_next_line(fd, &line);
		if (ret > 0)
			printf("%s\n", line);
		if (ret == 0)
		{
			printf("----------\nClosing...\n");
			close(fd);
			return (0);
		}
		if (ret < 0)
		{
			printf("Error. Return value of %d\n", ret);
			return (ret);
		}
	}
	close(fd);
	return (0);
}
