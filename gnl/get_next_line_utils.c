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

// int main(int argc, char **argv)
// {
// 	if (argc == 3)
// 	{
// 		char *my_output = gnl_strndup(argv[1], atoi(argv[2]));
// 		char *their_output = strndup(argv[1], atoi(argv[2]));
		
// 		if (!(strcmp(my_output, their_output)))
// 			printf("Success! Output string: %s\n", my_output);
// 		else
// 			printf("Failed...\nMine: %s\nActl: %s\n", my_output, their_output);
// 	}
// 	return (EXIT_SUCCESS);
// }

char	*find_newline(char *str)
{
	if (*str)
	{
		while (*str)
		{
			if (*str == '\n')
				return (str);
		}
	}
	return (NULL);
}

char	*gnl_strjoin(char *s1, char *s2)
{
	char	*output;
	char	*output_start;
	char	*s1_start;

	if (!s1)
		s1 = gnl_strndup("", 0);
	if (!s1)
		return (NULL);
	output = malloc(gnl_strlen(s1) + gnl_strlen(s2) + 1);
	output_start = output;
	s1_start = s1;
	if (!output)
		return (NULL);
	while (*s1)
		*output++ = *s1++;
	while (*s2)
		*output++ = *s2++;
	free(s1_start);
	return (*output = '\0', output_start);
}

// int main(int argc, char **argv)
// {
// 	if (argc == 3)
// 	{
// 		char	*output = gnl_strjoin(argv[1], argv[2]);
// 		printf("Output: %s\n", output);
// 	}
// 	return (0);
// }