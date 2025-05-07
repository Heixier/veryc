/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_to_c.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsiah <rsiah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 18:51:22 by rsiah             #+#    #+#             */
/*   Updated: 2025/01/13 18:51:41 by rsiah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Returns a duplicate of a string up to char C (uses malloc)
char	*split_to_char(char *str, char c)
{
	char	*output;
	int		size;

	size = ft_count_to_c(str, c);
	if (size < 0)
		return (NULL);
	output = ft_calloc(size + 1, 1);
	ft_memcpy(output, str, size);
	return (output);
}
