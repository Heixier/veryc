/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anteo <anteo@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 23:18:24 by anteo             #+#    #+#             */
/*   Updated: 2024/05/28 18:44:58 by anteo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t			len;
	unsigned int	i;
	char			*res;

	if (s == NULL || f == NULL)
		return (NULL);
	len = ft_strlen(s);
	res = (char *)malloc((len + 1) * sizeof(char));
	if (!res)
		return (NULL);
	i = 0;
	while (s[i])
	{
		res[i] = f(i, s[i]);
		i++;
	}
	res[i] = '\0';
	return (res);
}
/*
#include <stdio.h>

char	func(unsigned int i, char c)
{
	(void)i;
	return (ft_toupper(c));
}

int	main(void)
{
	char *str = "Hello World!";
	printf("Before str: %s\n", str);
	char *res = ft_strmapi(str, func);	
	printf("After str: %s\n", res);
}
*/
