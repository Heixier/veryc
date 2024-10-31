/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsiah <rsiah@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 15:40:01 by rsiah             #+#    #+#             */
/*   Updated: 2024/05/16 15:40:02 by rsiah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Copies up to size - 1 characters from the NUL-terminated 
 * string SRC to DST, NUL-terminating the result. 
 */
size_t	ft_strlcpy(char *dest, const char *str, size_t size)
{
	size_t	i;

	i = 0;
	if (!size)
		return (ft_strlen(str));
	while (i < (size - 1) && str[i])
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
	return (ft_strlen(str));
}

// compile me with -lbsd
//
// #include <bsd/string.h>

// int	main(int argc, char **argv)
// {
// 	if (argc == 4)
// 	{
// 		char *argv1_dup = strdup(argv[1]);
// 		char *argv1_dup2 = strdup(argv[1]);
// 		printf("Before: %s\n\n", argv[1]);
// 		size_t output_return = ft_strlcpy(argv1_dup, 
// 		argv[2], atoi(argv[3]));
// 		size_t expect_return = strlcpy(argv1_dup2, 
// 		argv[2], atoi(argv[3]));
// 		printf("Output after: %s\nOutput return: %ld\n\n
// 		Expect after: %s\nExpect return: %ld\n\n", 
// 		argv1_dup, output_return, argv1_dup2, expect_return);
// 		if (!(expect_return && output_return))
// 		{
// 			printf("Return value does not match! Difference: %ld\n", 
// 			expect_return - output_return);
// 			return (EXIT_SUCCESS);
// 		}
// 		if ((size_t)(strlen(argv1_dup)) >= output_return)
// 			printf("Result String Length: %ld\nAttempted to copy: %ld\n
// 			Successful (or coincidence)!", 
// 			(strlen(argv[1])), output_return);
// 		else
// 			printf("Result String Length: %ld\nAttempted to copy: %ld\n
// 			Mismatch! (probably concatenated)",
// 			(strlen(argv[1])), output_return);
// 	}
// 	return (EXIT_SUCCESS);
// }