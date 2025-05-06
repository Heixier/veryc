/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsiah <rsiah@42singapore.sg>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 15:26:26 by anteo             #+#    #+#             */
/*   Updated: 2025/03/05 18:17:40 by rsiah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int			i;
	const unsigned char		*uc1;
	const unsigned char		*uc2;

	if (n == 0)
		return (0);
	i = 0;
	uc1 = (const unsigned char *)s1;
	uc2 = (const unsigned char *)s2;
	while (uc1[i] && (uc1[i] == uc2[i]) && (i < n - 1))
		i++;
	if ((uc1[i] - uc2[i]) > 0)
		return (1);
	else if ((uc1[i] - uc2[i]) < 0)
		return (-1);
	return (0);
}

/**
 * Compares two strings S1 and S2 up to char C and returns the difference
 */
int	ft_strccmp(const char *s1, const char *s2, char c)
{
	size_t			i;
	unsigned char	*us1;
	unsigned char	*us2;

	us1 = (unsigned char *)s1;
	us2 = (unsigned char *)s2;
	i = 0;
	if (!c)
		return (0);
	while (us1[i] && us1[i] == us2[i] && us1[i] != c)
		i++;
	return (us1[i] - us2[i]);
}

/*
#include <stdio.h>
#include <string.h>
int     main(void)
{
        int     ans1 = strncmp("Hello", "Hello World", 5);
        printf("The difference is: %d\n", ans1);
        int     ans2 = ft_strncmp("Hello", "Hello World", 5);
        printf("The difference is: %d\n", ans2);
        int     ans11 = strncmp("Hellz", "Hellb World", 5);
        printf("The difference is: %d\n", ans11);
        int     ans111 = ft_strncmp("Hellz", "Hellb World", 5);
        printf("The difference is: %d\n", ans111);
        int     ans3 = strncmp("Hello", "Hello World", 8);
        printf("The difference is: %d\n", ans3);
        int     ans4 = ft_strncmp("Hello", "Hello World", 8);
        printf("The difference is: %d\n", ans4);
        int     ans5 = strncmp("Hello", "Hello World", 100);
        printf("The difference is: %d\n", ans5);
        int     ans6 = ft_strncmp("Hello", "Hello World", 100);
        printf("The difference is: %d\n", ans6);
}
*/
