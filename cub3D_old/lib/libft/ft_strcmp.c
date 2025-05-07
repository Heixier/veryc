/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsiah <rsiah@42singapore.sg>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 15:26:26 by anteo             #+#    #+#             */
/*   Updated: 2025/03/03 20:08:04 by rsiah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned int			i;
	const unsigned char		*uc1;
	const unsigned char		*uc2;

	if (!s1 || !s2)
		return (0);
	i = 0;
	uc1 = (const unsigned char *)s1;
	uc2 = (const unsigned char *)s2;
	while (uc1[i] && uc1[i] == uc2[i])
		i++;
	if ((uc1[i] - uc2[i]) > 0)
		return (1);
	else if ((uc1[i] - uc2[i]) < 0)
		return (-1);
	return (0);
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
