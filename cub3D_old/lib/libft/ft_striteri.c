/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anteo <anteo@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 18:01:57 by anteo             #+#    #+#             */
/*   Updated: 2024/05/28 18:45:17 by anteo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}
/*
#include <stdio.h>

void	func(unsigned int i, char *c)
{
	(void)i;
	*c = (char)ft_toupper((int)*c);
}

int     main(void)
{
        char str[] = "Hello World!";
        printf("Before str: %s\n", str);
        ft_striteri(str, func);
        printf("After str: %s\n", str);
}
*/
