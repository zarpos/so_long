

#include "so_long.h"

//With this function you are going to see how many lines
//are in the file, sorting by "\n"
static int	line_count(char *file)
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

//Allocates memory for the array of strings that is the map
static char	**line_allocation(char *file)
{
	char	**map;
	int		number_lines;

	number_lines = line_count(*file);
	if (number_lines <= 0)
		return (Error("Reading error, file may not exist"));
	map = malloc(sizeof(char *) * number_lines + 1);
	if (!map)
		return (Error("malloc failed to alloc map"));
	return (map);
}

// With the memory allocated, creates a 2D char map
char	**read_map(char *file)
{
	
}