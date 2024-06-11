#include "get_next_line.h"

size_t	gnl_strlen(char *str)
{
	size_t	length;

	length = 0;
	if (!str)
		return (0);
	while (str[length])
		length++;
	return (length);
}

// int main(int argc, char **argv)
// {
// 	(void)argc;
// 	printf("Output length: %ld\nExpected length: %ld\n", gnl_strlen(argv[1]), strlen(argv[1]));
// 	return (EXIT_SUCCESS);
// }

char	*gnl_strndup(char *str, size_t n)
{
	char	*output;
	size_t	str_len;
	size_t	i;

	if (!str || !n)
		return (NULL);
	i = 0;
	str_len = gnl_strlen(str);
	if (n > str_len)
		n = str_len;
	output = malloc(str_len + 1);
	if (!output)
		return (NULL);
	while (str[i] && i < n)
	{
		output[i] = str[i];
		i++;
	}
	output[i] = '\0';
	return (output);
}

int main(int argc, char **argv)
{
	if (argc == 3)
	{
		char *my_output = gnl_strndup(argv[1], atoi(argv[2]));
		char *their_output = strndup(argv[1], atoi(argv[2]));
		
		if (!(strcmp(my_output, their_output)))
			printf("Success! Output string: %s\n", my_output);
		else
			printf("Failed...\nMine: %s\nActl: %s\n", my_output, their_output);
	}
	return (EXIT_SUCCESS);
}

still testing halfway but seems to work