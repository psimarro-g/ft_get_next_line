/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psimarro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 19:50:26 by psimarro          #+#    #+#             */
/*   Updated: 2022/06/13 19:50:29 by psimarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*line;
	static char	*buffer[OPEN_MAX];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer[fd] = get_line(fd, buffer[fd]);
	if (!buffer[fd])
		return (NULL);
	line = trim_line(buffer[fd]);
	buffer[fd] = save_rest(buffer[fd]);
	return (line);
}

char	*get_line(int fd, char *buff)
{
	char	*chunk;
	int		readres;

	chunk = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!chunk)
		return (NULL);
	readres = 1;
	while (readres && !ft_strchr(buff, '\n'))
	{
		readres = read(fd, chunk, BUFFER_SIZE);
		if (readres == -1)
		{
			free(chunk);
			return (NULL);
		}
		chunk[readres] = '\0';
		buff = ft_free_strjoin(buff, chunk);
	}
	free (chunk);
	return (buff);
}

char	*trim_line(char *buff)
{
	char	*line;
	int		i;

	i = 0;
	if (!buff[0])
		return (NULL);
	while (buff[i] != '\n' && buff[i] != '\0')
		i++;
	line = ft_calloc(i + 2, sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (buff[i] != '\n' && buff[i] != '\0')
	{
		line[i] = buff[i];
		i++;
	}
	if (buff[i] == '\n')
		line[i] = '\n';
	return (line);
}

char	*save_rest(char *buff)
{
	char	*remaining;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (buff[i] && buff[i] != '\n')
		i++;
	if (!buff[i])
	{
		free(buff);
		return (NULL);
	}
	remaining = ft_calloc(ft_strlen(buff) - i++, sizeof(char));
	if (!remaining)
		return (NULL);
	while (buff[i])
		remaining[j++] = buff[i++];
	remaining[j] = '\0';
	free(buff);
	return (remaining);
}
