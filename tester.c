#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

# define EXE "./so_long"

void	print_arr(char **arr, char *header)
{
	int	i;
	
	i = 0;
	printf("%s\n", header);
	while (arr[i])
	{
		printf("%d: %s\n", i, arr[i]);
		i++;
	}
	printf("\n");
}

int	main(int argc, char **argv, char **envp)
{
	int		i;
	char	*args[3];
	int		pid;

	if (argc < 2)
		return (printf("invalid arguments. format: program, files\n"), 1);

	i = 2;
	args[0] = argv[1];
	args[2] = NULL;
	print_arr(argv, "Preparing to execute:");
	while (argv[i])
	{
		args[1] = argv[i];
		printf("Checking: \e[38;5;141;1m%s %s\e[0m\n", argv[1], args[1]);
		pid = fork();
		if (pid == 0)
		{
			execve(argv[1], args, envp);
			perror(argv[1]);
			return (1);
		}
		wait(NULL);
		i++;
	}
	return (0);
}