/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsiah <rsiah@42singapore.sg>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 17:53:33 by anteo             #+#    #+#             */
/*   Updated: 2025/03/13 02:13:34 by rsiah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Returns a pointer to the character C in S if found, else returns NULL
char	*ft_strchr(const char *s, int c)
{
	unsigned int	len;
	unsigned char	uc;

	if (!s)
		return (NULL);
	uc = (unsigned char)c;
	len = ft_strlen(s);
	if (uc == '\0')
		return ((char *)s + len);
	while (*s)
	{
		if ((unsigned char)*s == uc)
			return ((char *)s);
		s++;
	}
	return (NULL);
}
/*
#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	if (argc == 1)
	{
		printf("Error: input string and char");
		return (1);
	}
	if (argc == 3)
	{
		char	*s1 = argv[1];
		char	s2 = argv[2][0];
		char	*str;
		str = ft_strchr(s1, (int)s2);
		printf("%s\n", str);
	}
	return (0);
}
*/
