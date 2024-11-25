/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsiah <rsiah@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 12:42:46 by rsiah             #+#    #+#             */
/*   Updated: 2024/05/15 12:42:47 by rsiah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Returns a pointer to the last occurence of the character C in the string S.
 */
char	*ft_strrchr(const char *s, int c)
{
	const char	*last;

	last = NULL;
	while (*s)
	{
		if (*s == (unsigned char)c)
			last = s;
		s++;
	}
	if (!(unsigned char)c)
		return ((char *)s);
	return ((char *)last);
}

// int	main(int argc, char **argv)
// {
// 	if (argc == 3)
// 	{
// 		char *output = ft_strrchr(argv[1], *argv[2]);
// 		char *expected = strrchr(argv[1], *argv[2]);
// 		printf("Output: %p\n", output);
// 		printf("Expected: %p\n", expected);
// 		if (output == expected)
// 			printf("[strrchr] Success!\n");
// 		else
// 			printf("[strrchr] Failed...\n");
// 	}
// 	return (0);
// }