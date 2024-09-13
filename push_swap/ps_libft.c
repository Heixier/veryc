/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libft.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsiah <rsiah@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 15:05:40 by rsiah             #+#    #+#             */
/*   Updated: 2024/05/15 15:05:41 by rsiah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Sets N bytes to zeroes starting from S.
 */
void	ft_bzero(void *s, size_t n)
{
	char	*proxy;

	proxy = s;
	while (n)
	{
		*proxy = '\0';
		proxy++;
		n--;
	}
}

/**
 * Copies up to size - 1 characters from the NUL-terminated 
 * string SRC to DST, NUL-terminating the result. 
 */
size_t	ft_strlcpy(char *dest, const char *str, size_t size)
{
	size_t	i;

	i = 0;
	if (!size)
		return (ft_strlen(str));
	while (i < (size - 1) && str[i])
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
	return (ft_strlen(str));
}

/**
 * Returns the number of bytes in the string pointed to by S.
 */
size_t	ft_strlen(const char *s)
{
	int	count;

	count = 0;
	while (s[count])
		count++;
	return (count);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*output;
	size_t	n;

	if (nmemb == 0 || size == 0)
		return (NULL);
	n = nmemb * size;
	if (n / nmemb != size)
		return (NULL);
	output = malloc(n);
	if (!output)
		return (output);
	return (ft_bzero(output, n), output);
}

char	*ft_strdup(const char *s)
{
	char	*output;

	output = ft_calloc(ft_strlen(s) + 1, sizeof(char));
	if (!output)
		return (output);
	else
		return (ft_memcpy(output, s, ft_strlen(s)), output);
}
