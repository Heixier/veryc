/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsiah <rsiah@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 16:41:07 by rsiah             #+#    #+#             */
/*   Updated: 2024/05/20 16:41:07 by rsiah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"

/**
 * Copy N bytes of SRC to DEST.
 */
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	void	*start_dest;

	if (!dest && !src)
		return (dest);
	start_dest = dest;
	while (n--)
		*((unsigned char *)dest++) = *((unsigned char *)src++);
	return (start_dest);
}

static	size_t	count_words(char const *s, char c)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	if (s)
	{
		while (s[i])
		{
			if (s[i] != c && (s[i + 1] == c || !(s[i + 1])))
				count++;
			i++;
		}
	}
	return (count);
}

/**
 * Returns the length of the string delimited by C or NULL 
 */
static	size_t	ft_ultimate_strlen(const char *str, char c)
{
	size_t	output;

	output = 0;
	while (str[output] && str[output] != c)
		output++;
	return (output);
}

void	array_free(char **str_arr, int array_flag)
{
	char	**start_addr;

	if (array_flag != 1)
		return ;
	start_addr = str_arr;
	while (*str_arr)
	{
		free(*str_arr);
		*str_arr = NULL;
		str_arr++;
	}
	free(start_addr);
}

char	**ps_split(char const *s, char c)
{
	char	**output;
	size_t	i;
	size_t	words;

	words = count_words(s, c);
	i = 0;
	output = malloc((words + 1) * sizeof(char *));
	if (!output)
		return (NULL);
	while (i < words)
	{
		while (*s == c)
			s++;
		output[i] = ft_calloc(ft_ultimate_strlen(s, c) + 1, sizeof(char));
		if (!output[i])
			return (array_free(output, 1), NULL);
		ft_strlcpy(output[i], s, ft_ultimate_strlen(s, c) + 1);
		s += ft_ultimate_strlen(s, c);
		i++;
	}
	output[words] = NULL;
	return (output);
}
