#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static t_fstatus	*file_info;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	file_info = malloc(sizeof(t_fstatus));
	while (file_info->newline_ptr != '\n')
	{
		
	}
}
