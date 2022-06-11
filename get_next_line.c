#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*line;
	static char	*saved;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	saved = create_line(fd, saved);
	if (!saved)
		return (NULL);
	line = trim_saved(saved);
	saved = save_remaining(saved);
	return (line);
}

char	*create_line(int fd, char *saved)
{
	char	*buffer;
	int		readres;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	readres = 1;
	while (readres && !ft_strchr(saved, '\n'))
	{
		readres = read(fd, buffer, BUFFER_SIZE);
		if (readres == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[readres] = '\0';
		saved = free_strjoin(saved, buffer);
	}
	free (buffer);
	return (saved);
}

char	*trim_saved(char *saved)
{
	char	*line;
	int		i;

	i = 0;
	if (!saved[0])
		return (NULL);
	while (saved[i] != '\n' && saved[i] != '\0')
		i++;
	line = malloc(sizeof(char) * (i + 1 + ((int)saved[i] % 3)));
	if (!line)
		return (NULL);
	line[i + ((int)saved[i] % 3)] = '\0';
	i = 0;
	while (saved[i] != '\n' && saved[i] != '\0')
	{
		line[i] = saved[i];
		i++;
	}
	if (saved[i] == '\n')
		line[i] = '\n';
	return (line);
}

char	*save_remaining(char *saved)
{
	char	*remaining;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (saved[i] && saved[i] != '\n')
		i++;
	if (!saved[i])
	{
		free(saved);
		return (NULL);
	}
	remaining = malloc(sizeof(char) * (ft_strlen(saved) - i++));
	if (!remaining)
		return (NULL);
	while (saved[i])
		remaining[j++] = saved[i++];
	remaining[j] = '\0';
	free(saved);
	return (remaining);
}
