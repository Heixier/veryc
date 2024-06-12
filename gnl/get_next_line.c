#include "get_next_line.h"

char	*return_output_set_remainder(char **remainder, char *buffer)
{
	char	*output;
	char	*newline;

	newline = find_newline(buffer);
	output = gnl_strndup(buffer, newline - buffer);
	*remainder = find_newline(remainder);
	*remainder++;
	printf("Output: %s\nRemainder: %s\n", output, *remainder);
	return (output);
}

char	*get_next_line(int fd)
{
	static	char	*remainder = NULL;
	char			*output;
	char			*buffer;
	ssize_t			bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	while (bytes_read > 0)
	{
		remainder = gnl_strjoin(remainder, buffer);
		if (!remainder)
			return (free(buffer), NULL);
		if (find_newline(buffer))
			return (return_output_set_remainder(&remainder, buffer));


		bytes_read = read(fd, buffer, BUFFER_SIZE);
	}
}
