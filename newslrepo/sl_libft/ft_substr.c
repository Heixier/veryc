/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsiah <rsiah@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 15:51:40 by rsiah             #+#    #+#             */
/*   Updated: 2024/05/18 15:51:40 by rsiah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Allocates with ft_calloc and returns a substring from the string S.
 * The substring begins at index START and is of maximum size LEN 
 */
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*output;
	size_t	str_len;

	str_len = ft_strlen(s);
	if (start >= str_len || !len || !s)
		return (ft_calloc(1, sizeof(char)));
	if ((str_len - start) < len)
		len = str_len - start;
	output = ft_calloc(len + 1, sizeof(char));
	if (!output)
		return (NULL);
	ft_memcpy(output, &s[start], len);
	return (output);
}

// int	main(int argc, char **argv)
// {
// 	if (argc == 4)
// 	{
// 		char *out = ft_substr(argv[1], atoi(argv[2]), atoi(argv[3]));
// 		if (out)
// 		{
// 			printf("Original: %s\nSubstring [start: %d len: %d]:\n%s\n", 
// 			argv[1], atoi(argv[2]), atoi(argv[3]), out);
// 			free(out);
// 		}
// 		else
// 		{
// 			free(out);
// 			printf("Failed to allocate memory or empty string...\n");
// 		}
// 		return (EXIT_SUCCESS);
// 	}
// }
// int	main(void)
// {
// 	char *str = strdup("0123456789");
// 	char *s = ft_substr(str, 9, 10);
// 	printf("S: %s\n", s);
// 	free(s);
// 	free(str);
// 	return (0);
// }