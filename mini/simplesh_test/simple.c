#include "simple.h"

t_simp	*init_simp(char **envp)
{
	t_simp	*simp;

	simp = ft_calloc(sizeof(t_simp), 1);
	if (!simp)
		return (NULL);
	simp -> envp = envp;
	simp -> running = 1;
	return (simp);
}

int	main(int argc, char **argv, char **envp)
{
	char	*command;
	t_simp	*simp;

	(void)argc;
	(void)argv;

	simp = init_simp(envp);
	if (!simp)
		return (perror("malloc"), 1); // malloc guard necessary?
	sig_setter();
	init_custom_builtins(simp);
	if (!simp -> custom_builtins)
		return (perror("malloc"), 1);
	while (simp -> running)
	{
		command = readline("\e[38;5;118;1mpromp$\e[0m ");
		if (!command) // CTRL D EOF
			(printf("exit\n"), simp -> running = 0);
		command_handler(simp, command);
		ft_free(command); // should this be outside?
	}
	ms_cleanup(simp);
	return (simp -> exit_code);
}