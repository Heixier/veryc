#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 50
# endif

typedef struct s_fstatus
{
	char	*buffer;
	char	*newline_ptr;
	char	*chunk;
}			t_fstatus;

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <unistd.h>

#endif
