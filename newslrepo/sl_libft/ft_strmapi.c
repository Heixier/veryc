/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsiah <rsiah@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 20:42:11 by rsiah             #+#    #+#             */
/*   Updated: 2024/05/23 20:42:12 by rsiah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// static	char	offset_char(unsigned int index, char c)
// {
// 	c += index;
// 	return (c);
// }

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	index;
	char			*output;

	if (!s || !f)
		return (NULL);
	index = -1;
	output = ft_strdup(s);
	if (!output)
		return (output);
	while (s[++index])
		output[index] = f(index, s[index]);
	return (output);
}

// int	main(int argc, char **argv)
// {
// 	argc += 1;
// 	printf("Output: %s\n",ft_strmapi(argv[1], &offset_char));
// 	return (EXIT_SUCCESS);
// }