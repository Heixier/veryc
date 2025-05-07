/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsiah <rsiah@42singapore.sg>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 19:40:08 by anteo             #+#    #+#             */
/*   Updated: 2025/03/03 20:26:33 by rsiah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*gnl_free(void **buffer, void **buffer2)
{
	if (buffer && *buffer)
	{
		free(*buffer);
		*buffer = NULL;
	}
	if (buffer2 && *buffer2)
	{
		free(*buffer2);
		*buffer2 = NULL;
	}
	return (NULL);
}

ssize_t	read_nl(char **rem_line, int *fd, char **buffer, char **temp)
{
	ssize_t	bytes_read;

	bytes_read = 1;
	while (bytes_read > 0 && !gnl_strchr(*rem_line, '\n'))
	{
		bytes_read = read(*fd, *buffer, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			gnl_free((void **)rem_line, (void **)buffer);
			return (-1);
		}
		(*buffer)[bytes_read] = '\0';
		*temp = gnl_strjoin(*rem_line, *buffer);
		if (*temp == NULL)
			return (-1);
		gnl_free((void **)rem_line, NULL);
		*rem_line = *temp;
	}
	return (bytes_read);
}

int	extract_line(char *nl_position, char **rem_line, char **line, char **temp)
{
	size_t	len;

	len = (nl_position - *rem_line) + 1;
	*line = gnl_substr(*rem_line, 0, len);
	if (*line == NULL)
		return (-1);
	*temp = ft_strdup(nl_position + 1);
	if (*temp == NULL)
	{
		gnl_free((void **)line, NULL);
		return (-1);
	}
	gnl_free((void **)rem_line, NULL);
	*rem_line = ft_strdup(*temp);
	if (*rem_line == NULL)
	{
		gnl_free((void **)temp, (void **)line);
		return (-1);
	}
	gnl_free((void **)temp, NULL);
	return (0);
}

char	*append_newline(char **rem_line, char **line, char **temp)
{
	char	*nl_position;

	nl_position = gnl_strchr(*rem_line, '\n');
	if (nl_position)
	{
		if (extract_line(nl_position, rem_line, line, temp) == -1)
			return (NULL);
	}
	else
	{
		*line = ft_strdup(*rem_line);
		if (*line == NULL)
			return (gnl_free((void **)rem_line, NULL));
		gnl_free((void **)rem_line, NULL);
	}
	return (*line);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	char		*temp;
	static char	*rem_line[1024] = {NULL};
	char		*line;
	ssize_t		bytes_read;

	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE <= 0)
		return (gnl_free((void **)&rem_line[fd], NULL));
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (buffer == NULL)
		return (NULL);
	if (rem_line[fd] == NULL)
	{
		rem_line[fd] = ft_strdup("");
		if (rem_line[fd] == NULL)
			return (gnl_free((void **)&buffer, NULL));
	}
	bytes_read = read_nl(&rem_line[fd], &fd, &buffer, &temp);
	if (bytes_read == -1 || (bytes_read == 0 && *rem_line[fd] == '\0'))
		return (gnl_free((void **)&buffer, (void **)&rem_line[fd]));
	gnl_free((void **)&buffer, NULL);
	return (append_newline(&rem_line[fd], &line, &temp));
}
