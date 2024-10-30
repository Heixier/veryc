/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsiah <rsiah@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 13:23:26 by rsiah             #+#    #+#             */
/*   Updated: 2024/05/17 13:23:27 by rsiah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Appends the NUL-terminated string SRC
 * to the end of DST. It will append at most
 * size - strlen(DST) - 1 bytes, 
 * NUL-terminating the result. 
 */
size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	output;

	if ((size <= (ft_strlen(dest))) || size == 0)
		return ((ft_strlen(src) + size));
	else
		output = ft_strlen(dest) + ft_strlen(src);
	size -= ft_strlen(dest);
	dest += ft_strlen(dest);
	while (--size && *src)
		*dest++ = *src++;
	*dest = '\0';
	return (output);
}

// #include <bsd/string.h>
// int	main(int argc, char **argv)
// {
// 	if (argc == 4)
// 	{
// 		char *my_dest = strdup(argv[1]);
// 		char *their_dest = strdup(argv[1]);
// 		printf("Original: %s\n\n", argv[1]);
// 		size_t	my_return = ft_strlcat(my_dest, 
// 		argv[2], atoi(argv[3]));
// 		size_t their_return = strlcat(their_dest, 
// 		argv[2], atoi(argv[3]));
// 		printf("Output: %s[%ld]\nExpect: %s[%ld]\n\n", 
// 		my_dest, my_return, their_dest, their_return);
// 		if (!strcmp(my_dest, their_dest))
// 			printf("String matched!\n");
// 		else
// 			printf("String match fail...\n");
// 		if (my_return == their_return)
// 			printf("Return matched!\n");
// 		else
// 			printf("Return value fail...\n");
// 	}
// 	return (EXIT_SUCCESS);
// }