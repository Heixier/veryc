/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinfree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsiah <rsiah@42singapore.sg>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 21:44:46 by rsiah             #+#    #+#             */
/*   Updated: 2025/04/10 21:24:27 by rsiah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	write_to_output(char *output, char *src);

// Returns a new combined string and frees the second
char	*ft_strjoinfree(char *s1, char *s2)
{
	int		i;
	char	*output;

	if (!s1)
		s1 = ft_strndup("", 0);
	if (!s1)
		return (NULL);
	output = ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1, 1);
	if (!output)
		return (NULL);
	i = write_to_output(output, s1);
	if (!s2)
		return (output);
	write_to_output(&(output[i]), s2);
	ft_free((void **)&s2);
	return (output);
}

static int	write_to_output(char *output, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		output[i] = src[i];
		i++;
	}
	return (i);
}
