/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsiah <rsiah@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 22:24:26 by rsiah             #+#    #+#             */
/*   Updated: 2024/05/30 22:24:27 by rsiah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/**
 * strjoin - concatenates two strings S1 and S2
 * returns a new malloc'd string after freeing S1
 */
char	*gnl_strjoin(char *s1, char const *s2)
{
	char	*output;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	output = malloc(gnl_strlen(s1) + gnl_strlen(s2) + 1);
	if (output)
	{
		while (s1[i])
		{
			output[i] = s1[i];
			i++;
		}
		while (s2[j])
			output[i++] = s2[j++];
		output[i] = '\0';
	}
	free(s1);
	return (output);
}

size_t	gnl_strlen(const char *s)
{
	int	count;

	count = 0;
	if (!s)
		return (0);
	while (s[count])
		count++;
	return (count);
}

/**
 * Returns null if it can't find C
 * Else return pointer to found C in S
 */
char	*gnl_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == (unsigned char)c)
			return ((char *)s);
		s++;
	}
	if (!(unsigned char)c)
		return ((char *)s);
	return (NULL);
}

/**
 * @brief Returns a NUL-terminated duplicate of S up to N bytes
 */
char	*gnl_strndup(const char *s, size_t n)
{
	char	*output;
	size_t	output_idx;
	size_t	output_len;

	if (!s)
		return (NULL);
	output_len = gnl_strlen(s);
	if (output_len > n)
		output_len = n;
	output = malloc(output_len + 1);
	if (!output)
		return (NULL);
	output_idx = 0;
	while (s[output_idx] && output_idx < n)
	{
		output[output_idx] = (char)s[output_idx];
		output_idx++;
	}
	output[output_idx] = '\0';
	return (output);
}
