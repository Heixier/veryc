/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsiah <rsiah@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 12:11:40 by rsiah             #+#    #+#             */
/*   Updated: 2024/05/30 12:11:40 by rsiah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*split_char(char *str, int option)
{
	char	*output;
	char	*newline_ptr;

	newline_ptr = gnl_strchr(str, '\n');
	if (option == BEFORE)
		output = gnl_strndup(str, (newline_ptr - str + 1));
	else
	{
		output = gnl_strndup((newline_ptr + 1), gnl_strlen(newline_ptr + 1));
		free(str);
	}
	return (output);
}

char	*read_error(char **remainder, char **chunk)
{
	free(*chunk);
	if (*remainder)
		return (free(*remainder), *remainder = NULL, NULL);
	return (NULL);
}

char	*make_remainder(int fd, char **remainder)
{
	char	*chunk;
	ssize_t	bytes_read;

	chunk = malloc(BUFFER_SIZE + 1);
	if (!chunk)
		return (NULL);
	bytes_read = read(fd, chunk, BUFFER_SIZE);
	while (bytes_read >= 0)
	{
		chunk[bytes_read] = '\0';
		if (!*remainder)
			*remainder = gnl_strndup("", 0);
		*remainder = gnl_strjoin(*remainder, chunk);
		if (gnl_strchr(*remainder, '\n'))
			return (free(chunk), *remainder);
		if (bytes_read <= 0)
			break ;
		bytes_read = read(fd, chunk, BUFFER_SIZE);
	}
	if (bytes_read < 0)
		return (read_error(remainder, &chunk));
	return (free(chunk), *remainder);
}

char	*get_next_line(int fd)
{
	static char	*remainder;
	char		*output_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	remainder = make_remainder(fd, &remainder);
	if (!remainder || !(*remainder))
		return (free(remainder), remainder = NULL, NULL);
	if (gnl_strchr(remainder, '\n'))
	{
		output_line = split_char(remainder, BEFORE);
		return (remainder = split_char(remainder, AFTER), output_line);
	}
	output_line = gnl_strndup(remainder, gnl_strlen(remainder));
	return (free(remainder), remainder = NULL, output_line);
}

int	main(int argc, char **argv)
{
	char	*output;
	char	running[100];
	size_t	count = 0;

	(void)argc;
	int fd = open(argv[1], O_RDONLY);
	*running = '\0';

	printf(MY_CYAN MY_BOLD"~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n🔥 Interactive "
	MY_LIGHT_GREEN MY_UNDERLINE
	"GNL" MY_CYAN MY_BOLD" viewer 🔥\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"MY_END);
	printf("Current buffer size: "MY_RED MY_BOLD "%d\n" MY_END, BUFFER_SIZE);
	printf("Enter any character to advance\n");
	printf("Enter \"!\" to quit || \"?\" to dump contents\n");
	printf(MY_BLINK MY_LIGHT_PURPLE"BEGIN READ\n\n"MY_END);
	while (1)
	{
		output = get_next_line(fd);
		if (*running == '?' && !output)
		{
			printf(MY_LIGHT_PURPLE MY_BLINK"\nFile dumped!\n"MY_END);
			free(output);
			break ;
		}
		if (!output)
			printf(MY_LIGHT_RED
			"Nothing read! (EOF / Error) \"!\" to quit!\n"MY_END);
		else
		{
			count++;
			printf("[%ld] ", count);
			printf(MY_LIGHT_GREEN"%s$"MY_END, output);
		}
		if (!(*running == '?'))
		{
			printf(MY_BLACK);
			scanf("%s", running);
			if (*running == '!')
			{
				printf(MY_LIGHT_PURPLE MY_BLINK"Program Stopped!\n"MY_END);
				free(output);
				break ;
			}
			printf(MY_END);
		}
		else
			printf("\n"), usleep(15000);
		free(output);
	}
	close(fd);
	return (0);
}
