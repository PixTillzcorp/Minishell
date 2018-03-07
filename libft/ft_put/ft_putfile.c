#include "../includes/libft.h"

void		ft_putfile(char *path)
{
	char	*line;
	int		fd;

	if ((fd = open(path, O_RDONLY)) < 0)
		exit(EXIT_FAILURE);
	while (get_next_line(fd, &line) > 0)
	{
		ft_putendl(line);
		free(line);
	}
}