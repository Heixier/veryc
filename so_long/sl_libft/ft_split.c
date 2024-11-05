/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsiah <rsiah@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 16:41:07 by rsiah             #+#    #+#             */
/*   Updated: 2024/05/20 16:41:07 by rsiah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Wait isn't this strchr?*/
static	int	find_char(char c, char *seps)
{
	int	i;

	if (!seps)
		return (1);
	i = 0;
	while (seps[i])
	{
		if (c == seps[i])
			return (1);
		i++;
	}
	return (0);
}

static	size_t	count_words(char const *s, char *seps)
{
	size_t	output;
	int		word_state;

	output = 0;
	word_state = 0;
	if (s)
	{
		while (*s)
		{
			if (!find_char(*s, seps) && word_state == 0)
			{
				word_state = 1;
				output++;
			}
			else if (find_char(*s, seps))
				word_state = 0;
			s++;
		}
	}
	return (output);
}

/**
 * Returns the length of the string delimited by seps or NULL 
 */
static	size_t	ft_ultimate_strlen(const char *str, char *seps)
{
	size_t	output;

	output = 0;
	while (str[output] && !(find_char(str[output], seps)))
		output++;
	return (output);
}

void	free_array(char **str_arr)
{
	char	**start_addr;

	if (!str_arr)
		return ;
	start_addr = str_arr;
	while (*str_arr)
	{
		free(*str_arr);
		*str_arr = NULL;
		str_arr++;
	}
	free(start_addr);
	start_addr = NULL;
}

/** Returns an array delimited by any character in seps
 * (uses malloc for array and each item in array)
*/
char	**ft_split(char const *s, char *seps)
{
	char	**output;
	size_t	i;
	size_t	words;

	words = count_words(s, seps);
	i = 0;
	output = malloc((words + 1) * sizeof(char *));
	if (!output)
		return (ft_printfd(2, "Error\nmalloc error\n"), NULL);
	while (i < words)
	{
		while (find_char(*s, seps))
			s++;
		output[i] = ft_calloc(ft_ultimate_strlen(s, seps) + 1, sizeof(char));
		if (!output[i])
			return (free_array(output), NULL);
		ft_strlcpy(output[i], s, ft_ultimate_strlen(s, seps) + 1);
		s += ft_ultimate_strlen(s, seps);
		i++;
	}
	output[words] = NULL;
	return (output);
}

// int	main(int argc, char **argv)
// {
// 	if (argc == 3)
// 	{
// 		char	**string_array;
// 		size_t	i;

// 		if (strcmp(argv[1], "NULL") == 0)
// 			argv[1] = NULL;
// 		if (strcmp(argv[2], "NULL") == 0)
// 			*argv[2] = '\0';
// 		i = 0;
// 		string_array = ft_split(argv[1], *argv[2]);
// 		if (!string_array)
// 		{
// 			printf("Failed to create string array!\n");
// 			free(string_array);
// 		}
// 		else
// 		{
// 			while (string_array[i])
// 			{
// 				printf("String: %s\n", string_array[i]);
// 				i++;
// 			}
// 			free_strings_in_array(string_array);
// 			free(string_array);
// 		}
// 	}
// 	return (EXIT_SUCCESS);
// }