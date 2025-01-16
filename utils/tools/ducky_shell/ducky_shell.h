#ifndef DUCKY_BASH_H
# define DUCKY_BASH_H

#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

typedef struct s_info
{
	FILE	*src;
	FILE	*dest;
	char	*delay;
	char	*output_name;
	char	*buffer;
	int		buffer_size;
}				t_info;

void	write_commands(t_info *info);
void	cleanup(t_info **info);
t_info	*init_info(char **argv);
char	*ft_strdup(const char *s);

#endif