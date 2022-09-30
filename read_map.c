

#include "so_long.h"

//With this function you are going to see how many lines
//are in the file, sorting by "\n"
static int	line_count(int fd)
{
	char	c;
	int		fd;
	int		line;
	int		readcount;

	fd = open(file, O_RDONLY);
	if (!fd)
		return (-1);
	line = 1;
	while (fd != -1)
	{
		readcount = read(fd, &c, 1);
		if (readcount == 0)
			break ;
		if (readcount < 0)
			return (-1);
		if (c == '\n')
			line++;
	}
	close(fd);
	return (line);
}