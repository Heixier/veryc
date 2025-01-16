#include "ducky_shell.h"

char	*ft_strdup(const char *s)
{
	char			*ptr;
	size_t			len;
	unsigned int	i;

	if (s == NULL)
		return (NULL);
	len = strlen(s);
	ptr = calloc((len + 1), 1);
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (i <= len)
	{
		ptr[i] = s[i];
		i++;
	}
	return (ptr);
}

t_info	*init_info(char **argv)
{
	t_info	*info;

	info = calloc(sizeof(t_info), 1);
	if (!info)
		return (NULL);
	info -> buffer_size = 4000;
	return(info);
}

void	cleanup(t_info **info)
{
	if (!info)
		return ;
	free((*info) -> buffer);
	fclose((*info) -> src);
	(*info) -> src = NULL;
	fclose((*info) -> dest);
	(*info) -> dest = NULL;
	free((*info) -> output_name);
	(*info) -> output_name = NULL;
	free(*info);
	*info = NULL;
}

void	write_commands(t_info *info)
{
	char	*preamble;
	char	*prepend;
	char	*append;

	preamble = ft_strdup("LOCALE US\nDELAY 1000\n");
	if (!preamble)
		return ;
	prepend = ft_strdup("STRING ");
	if (!prepend)
		return ;
	append = ft_strdup("ENTER\nDELAY 500\nSTRING echo status: $?\nENTER\nDELAY 250\n");
	if (!append)
		return ;
	fprintf(info -> dest, "%s", preamble);
	while (fgets(info -> buffer, info -> buffer_size, info -> src))
	{
		if (*(info -> buffer) != '\n')
			fprintf(info -> dest, "%s%s%s", prepend, info -> buffer, append);
	}
	free(preamble);
	free(prepend);
	free(append);
}

int main(int argc, char **argv)
{
	char	*buffer;
	t_info	*info;

	if (argc < 2 || argc > 3)
		return (printf("Invalid argument format!\n"), 1);
	info = init_info(argv);
	if (!info)
		return (perror("calloc"), 1);
	if (argv[2])
		info -> output_name = ft_strdup(argv[2]);
	else
		info -> output_name = ft_strdup("output.txt");
	info -> buffer = calloc(info -> buffer_size + 1, 1);
	if (!info -> buffer)
		return (cleanup(&info), perror("malloc"), 1);

	info -> src = fopen(argv[1], "r");
	if (!info -> src)
		return (cleanup(&info), perror("fopen"), 1);
	info -> dest = fopen(info -> output_name, "w+");
	if (!info -> dest)
		return (cleanup(&info), perror("fopen"), 1);
	write_commands(info);
	cleanup(&info);
	return (0);
}