/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anteo <anteo@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 20:03:19 by anteo             #+#    #+#             */
/*   Updated: 2024/05/26 05:53:07 by jelly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char			*tmp;
	unsigned char	uc;

	uc = (unsigned char)c;
	if (uc == '\0')
		return ((char *)s + ft_strlen(s));
	tmp = NULL;
	while (*s)
	{
		if ((unsigned char)*s == uc)
			tmp = (char *)s;
		s++;
	}
	return (tmp);
}
/*
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
		(void)argv;
		char *str = ft_strrchr("asd", '\0');
		printf("%s\n", str);
	}
	if (argc == 3)
        {
                char    *s1 = argv[1];
                char    s2 = argv[2][0];
                char    *str;
                str = ft_strrchr(s1, (int)s2);
                printf("%s\n", str);
        }
        return (0);
}
*/
