#include "get_next_line.h"

char	*return_output_set_remainder(char **remainder, char *buffer)
{
	char	*output;
	char	*newline;

	newline = find_newline(buffer);
	output = gnl_strndup(buffer, newline - buffer);
	newline = find_newline(*remainder);
	if (newline)
		*remainder = newline + 1;
	else
		remainder = NULL;
	printf("Output: %s\nRemainder: %s\n", output, *remainder);
	return (output);
}

this is broken ^^

char	*get_next_line(int fd)
{
	static	char	*remainder = NULL;
	char			*buffer;
	ssize_t			bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	buffer[bytes_read] = '\0';
	while (bytes_read > 0)
	{
		remainder = gnl_strjoin(remainder, buffer);
		if (!remainder)
			return (free(buffer), NULL);
		if (find_newline(buffer))
			return (return_output_set_remainder(&remainder, buffer));
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		buffer[bytes_read] = '\0';
	}
	if (remainder && *remainder)
		return (return_output_set_remainder(&remainder, buffer));
	free(remainder);
	free(buffer);
	remainder = NULL;
	return (NULL);
}

int main(int argc, char **argv)
{
	int		fd;
	char	*output;

	if (argc == 2)
		fd = open(argv[1], O_RDONLY);
	else
		fd = open("test", O_RDONLY);
	
	while (1)
	{
		output = get_next_line(fd);
		if (!output)
		{
			printf("EOF reached\n");
			return (0);
		}
		printf("%s", output);
	}
	close(fd);
	return (0);
}