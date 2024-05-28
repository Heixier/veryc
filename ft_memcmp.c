/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsiah <rsiah@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 21:09:54 by rsiah             #+#    #+#             */
/*   Updated: 2024/05/15 21:09:55 by rsiah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/**
 *Compare N bytes of S1 and S2.
*/
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (!n)
		return (0);
	while (((unsigned char *)s1)[i] == ((unsigned char *)s2)[i] && i < n - 1)
		i++;
	return (((unsigned char *)s1)[i] - (((unsigned char *)s2)[i]));
}

// int	main(int argc, char **argv)
// {
// 	if (argc == 4)
// 	{
// 		int	output = ft_memcmp(argv[1], argv[2], atoi(argv[3]));
// 		int	expect = memcmp(argv[1], argv[2], atoi(argv[3]));
// 		printf("Output: %d\nExpect: %d\n", output, expect);
// 		if (output == expect)
// 			printf("Success!");
// 		else
// 			printf("Failure...");
// 	}
// 	return (EXIT_SUCCESS);
// }