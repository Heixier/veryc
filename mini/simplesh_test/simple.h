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
	t_list	*custom_builtins;
}				t_simp;

// Signals
void	sig_handler(int signal);
void	sig_setter(void);

// Cleanup
void	ms_cleanup(t_simp *simp);
void	ms_free_list(t_list *list);

// cmds
void	command_handler(t_simp *simp, char *cmdstr);
void	ms_exit(t_simp *simp);
void	ms_echo(t_simp *simp, char *path, char **args, char **envp);
void	init_custom_builtins(t_simp *simp);

// Info
void	ms_print_slist(t_list *list);
void	ms_print_sarray(char **array);

#endif