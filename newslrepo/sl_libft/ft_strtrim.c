/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsiah <rsiah@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 17:20:24 by rsiah             #+#    #+#             */
/*   Updated: 2024/05/18 17:20:24 by rsiah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	is_c_in_str(char c, const char *str)
{
	if (str)
	{
		while (*str)
			if (c == *str++)
				return (1);
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*output;

	if (!s1)
		return (NULL);
	start = 0;
	end = ft_strlen(s1);
	while (is_c_in_str(s1[start], set))
		start++;
	while (is_c_in_str(s1[end - 1], set))
		end--;
	if (end > start)
		output = ft_calloc((end - start) + 1, sizeof(char));
	else
		output = ft_calloc(1, sizeof(char));
	if (output)
		ft_strlcpy(output, &s1[start], (end - start) + 1);
	return (output);
}

// int	main(int argc, char **argv)
// {
// 	if (argc == 3)
// 	{
// 		if (!(strcmp(argv[1], "NULL")))
// 			argv[1] = NULL;
// 		if (!(strcmp(argv[2], "NULL")))
// 			argv[2] = NULL;
// 		char	*output = ft_strtrim(argv[1], argv[2]);
// 		printf("Result: %s\n", output);
// 		free(output);
// 	}
// 	return (EXIT_SUCCESS);
// }
