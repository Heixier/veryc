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

static	size_t	count_words(char const *s, char c)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	if (s)
	{
		while (s[i])
		{
			if (s[i] != c && (s[i + 1] == c || !(s[i + 1])))
				count++;
			i++;
		}
	}
	return (count);
}

/**
 * Returns the length of the string delimited by C or NULL 
 */
static	size_t	ft_ultimate_strlen(const char *str, char c)
{
	size_t	output;

	output = 0;
	while (str[output] && str[output] != c)
		output++;
	return (output);
}

static	void	free_strings_in_array_and_array(char **str_arr)
{
	char	**start_addr;

	start_addr = str_arr;
	while (*str_arr)
	{
		free(*str_arr);
		*str_arr = NULL;
		str_arr++;
	}
	free(start_addr);
}

char	**ft_split(char const *s, char c)
{
	char	**output;
	size_t	i;
	size_t	words;

	words = count_words(s, c);
	i = 0;
	output = malloc((words + 1) * sizeof(char *));
	if (!output)
		return (NULL);
	while (i < words)
	{
		while (*s == c)
			s++;
		output[i] = ft_calloc(ft_ultimate_strlen(s, c) + 1, sizeof(char));
		if (!output[i])
			return (free_strings_in_array_and_array(output), NULL);
		ft_strlcpy(output[i], s, ft_ultimate_strlen(s, c) + 1);
		s += ft_ultimate_strlen(s, c);
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