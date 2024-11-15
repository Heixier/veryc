#include "simple.h"

void	init_simp(t_simp *simp, char **envp);
{
	simp -> envp = envp;
}

int	main(int argc, char **argv, char **envp)
{
	char	*command;
	t_simp	*simp;

	simp = ft_calloc(sizeof(t_simp),1);
	if (!simp)
		return (1); // malloc guard necessary?
	sig_setter();
	while (simp -> running)
	{
		command = readline("\e[38;5;118;1mpromp$\e[0m ");
		if (!command)
			return (printf("exit\n"), simp -> exit_code);
		printf("%s\n", command);
	}
	return (simp -> exit_code);
}