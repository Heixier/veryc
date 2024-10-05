#ifndef PLAYGROUND_H
# define PLAYGROUND_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "mlx.h"
# include <fcntl.h>
# include <sys/wait.h>
# include <math.h>

# define WIDTH 50
# define HEIGHT 50

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits;
	int		size_line;
	int		endian;
}			t_img;

void	print_img(t_img *img);

#endif