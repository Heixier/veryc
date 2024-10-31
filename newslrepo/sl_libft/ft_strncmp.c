/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsiah <rsiah@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 12:53:49 by rsiah             #+#    #+#             */
/*   Updated: 2024/05/15 12:53:50 by rsiah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Compares two strings S1 and S2 up to N and returns the difference.
 */
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{	
	size_t			i;
	unsigned char	*us1;
	unsigned char	*us2;

	us1 = (unsigned char *)s1;
	us2 = (unsigned char *)s2;
	i = 0;
	if (!n)
		return (0);
	while (us1[i] && us1[i] == us2[i] && i < n - 1)
		i++;
	return (us1[i] - us2[i]);
}

// int	main(int argc, char **argv)
// {
// 	char *s1 = "\x12\xff\x65\x12\xbd\xde\xad";
//  	char *s2 = "\x12\x02";

// 	if (argc == 4)
// 	{
// 		int output = ft_strncmp(s1, s2, atoi(argv[3]));
// 		int expected = strncmp(s1, s2, atoi(argv[3]));
// 		if (expected == output)
// 			printf("Success!\nOutput: %d\nExpected: %d\n", output, expected);
// 		else
// 			printf("Failed...\nOutput: %d\nExpected: %d\n", output, expected);
// 	}
// 	return (EXIT_SUCCESS);
// }