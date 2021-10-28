#include "get_next_line.h"

int			finder(char *str)
{
	int i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_was_read(int fd, char *line)
{
	char		*buffer;
	int			was_read;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return(NULL);
	was_read = 1;
	while (!finder(line) && was_read)
	{
		was_read = read(fd, buffer, 1);
		if (was_read == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[was_read] = '\0';
		line = ft_strjoin(line, buffer);
	}
	free(buffer);
	return (line);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*remain;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	remain = ft_was_read(fd, remain);
	if (!remain)
		return (NULL);
	line = ft_linehelper(remain);
	remain = ft_get_remain(remain);
	return (line);
}
