/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anteo <anteo@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 16:43:10 by anteo             #+#    #+#             */
/*   Updated: 2024/05/26 07:54:49 by jelly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned int		i;
	const unsigned char	*ptr;
	unsigned char		uc;

	i = 0;
	ptr = (const unsigned char *)s;
	uc = (unsigned char)c;
	while (i < n)
	{
		if (ptr[i] == uc)
			return ((void *)(ptr + i));
		i++;
	}
	return (NULL);
}
/* unfinished:

#include <stdio.h>
#include <stdlib.h>

int     main(int argc, char **argv)
{
        if (argc == 1)
        {
                printf("Error: input string and char");
                return (1);
        }
        if (argc == 3)
        {
                char    *s1 = argv[1];
                char    s2 = argv[2][0];
                char	*s3 = argv[3];
		char    *str;
                str = ft_memchr(s1, (int)s2, (int)s3);
                printf("%s\n", str);
        }
        return (0);
}
*/
