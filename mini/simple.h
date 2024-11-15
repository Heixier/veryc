#ifndef SIMPLE_H
# define SIMPLE_H

# include "ms_libft/libft.h"
# include <stdio.h>
# include <sys/wait.h>
# include <stdlib.h>
# include <unistd.h>
# include <readline/readline.h>
# include <signal.h>

typedef struct s_simp
{
	int		running;
	int 	exit_code;
	int		err_code;
	char	**envp;
}				t_simp;

// Signals
void	sig_handler(int signal);
void	sig_setter(void);

#endif