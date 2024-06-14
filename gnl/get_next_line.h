#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 15
# endif

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <unistd.h>

size_t	gnl_strlen(char *str);
char	*gnl_strndup(char *str, size_t n);
char	*find_newline(char *str);
char	*gnl_strjoin(char *s1, char *s2);
char	*return_output_set_remainder(char **remainder, char *buffer);

#endif
