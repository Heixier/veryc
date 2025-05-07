/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsiah <rsiah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 21:51:59 by rsiah             #+#    #+#             */
/*   Updated: 2024/12/13 21:53:36 by rsiah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(char *str, size_t n)
{
	char	*output;
	size_t	str_len;
	size_t	i;

	i = 0;
	str_len = ft_strlen(str);
	if (n > str_len)
		n = str_len;
	output = malloc(n + 1);
	if (!output)
		return (NULL);
	while (str[i] && i < n)
	{
		output[i] = str[i];
		i++;
	}
	output[i] = '\0';
	return (output);
}
