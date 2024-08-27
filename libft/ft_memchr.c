/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsiah <rsiah@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 15:20:46 by rsiah             #+#    #+#             */
/*   Updated: 2024/05/15 15:20:47 by rsiah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * The  memchr()  function  scans  the  initial n bytes of the memory area
       pointed to by s for the first instance of c.  Both c and the  bytes  of
       the memory area pointed to by s are interpreted as unsigned char.
 */
void	*ft_memchr(const void *s, int c, size_t n)
{
	while (n--)
		if (*((const unsigned char *)s++) == (unsigned char)c);
			return ((void *)--s);
	return (NULL);
}

// int	main(int argc, char **argv)
// {
// 	if (argc == 3)
// 	{
// 		char to_find = *argv[2];
// 		printf("Output: %p\n", (char *)ft_memchr(argv[1],
// 		to_find, strlen(argv[1])));
// 		printf("Expect: %p\n", (char *)memchr(argv[1],
// 		to_find, strlen(argv[1])));
// 	}
// }