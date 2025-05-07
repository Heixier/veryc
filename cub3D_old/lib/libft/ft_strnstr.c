/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsiah <rsiah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 18:37:51 by anteo             #+#    #+#             */
/*   Updated: 2024/11/25 17:08:49 by rsiah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	unsigned int	i;
	unsigned int	j;

	if (*little == '\0')
		return ((char *)big);
	i = 0;
	while (big[i] && (i < len))
	{
		j = 0;
		while (i + j < len && little[j] && big[i + j] == little[j])
		{
			if (little[j + 1] == '\0')
				return ((char *)big + i);
			j++;
		}
		i++;
	}
	return (NULL);
}
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char *strb1 = "lorem ipsum dolor sit amet";
	char *strl1 = "lorem";
	char *strb2 = "abcdefghi012345#!";
	char *strl2 = "#";
	char *strb3 = "abcdefghi012345#!";
	char *strl3 = "f";
	char *strb4 = "f";
	char *strl4 = "f";
	char *strb5 = "2180";
	char *strl5 = "";

	char *res1 = ft_strnstr(strb1, strl1, 15);
//	char *res11 = strnstr(strb1, strl1, 10);
	char *res2 = ft_strnstr(strb2, strl2, 18);
//	char *res22 = strnstr(strb2, strl2, 10);
	char *res3 = ft_strnstr(strb3, strl3, 1);
//	char *res33 = strnstr(strb3, strl3, 1);
	char *res4 = ft_strnstr(strb4, strl4, 18);
//	char *res44 = strnstr(strb4, strl4, 10);
	char *res5 = ft_strnstr(strb5, strl5, 18);
//	char *res55 = strnstr(strb5, strl5, 10);

	printf("Result of ft_strnstr1: %s\n", res1);
//	printf("Result of strnstr1: %s\n", res11);
	printf("Result of ft_strnstr2: %s\n", res2);
//	printf("Result of strnstr2: %s\n", res22);
	printf("Result of ft_strnstr3: %s\n", res3);
//	printf("Result of strnstr3: %s\n", res33);
	printf("Result of ft_strnstr4: %s\n", res4);
//	printf("Result of strnstr4: %s\n", res44);
	printf("Result of ft_strnstr5: %s\n", res5);
//	printf("Result of strnstr5: %s\n", res55);

	return (0);
}
*/
