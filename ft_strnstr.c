/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsiah <rsiah@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 11:40:22 by rsiah             #+#    #+#             */
/*   Updated: 2024/05/17 11:40:22 by rsiah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	*search(char *start, char *end, size_t len)
{
	char	*temp;

	temp = start;
	while ((*start++ == *end++) && len--)
		if (!*end)
			return (temp);
	return (NULL);
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;

	i = 0;
	if (!*little)
		return ((char *)big);
	while (i < len && big[i])
	{
		if (search((char *)&big[i], (char *)little, len - i))
			return ((char *)&big[i]);
		i++;
	}
	return (NULL);
}

// compile me with -lbsd

// #include <bsd/string.h>
//
// int	main(int argc, char **argv)
// {
// 	if (argc == 4)
// 	{
// 		char	*output = ft_strnstr(argv[1], argv[2], atoi(argv[3]));
// 		char	*expect = strnstr(argv[1], argv[2], atoi(argv[3]));
// 		printf("Output: %s\nExpect: %s\n", output, expect);
// 		if (output == expect)
// 			printf("Match!\n");
// 		else
// 			printf("Fail...\n");
// 	}
// 	return (EXIT_SUCCESS);
// }