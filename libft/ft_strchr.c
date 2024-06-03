/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsiah <rsiah@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 17:54:25 by rsiah             #+#    #+#             */
/*   Updated: 2024/05/14 17:54:26 by rsiah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Returns a pointer to the first occurence of the character C in string S.
 */
char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (unsigned char)c)
			return ((char *)s);
		s++;
	}
	if (!(unsigned char)c)
		return ((char *)s);
	return (NULL);
}

// int	main(int argc, char **argv)
// {
// 	if (argc == 3)
// 	{
// 		char *output = ft_strchr(argv[1], *argv[2]);
// 		char *expected = strchr(argv[1], *argv[2]);
// 		printf("Output: %p\n", output);
// 		printf("Expected: %p\n", expected);
// 		if (output == expected)
// 			printf("Success!\n");
// 		else
// 			printf("Failed...\n");
// 	}
// 	return (0);
// }||