/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsiah <rsiah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 11:42:57 by rsiah             #+#    #+#             */
/*   Updated: 2025/01/17 15:10:59 by rsiah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Reallocate memory for a string to SIZE
char	*ft_str_realloc(char *str, size_t size)
{
	char	*new;

	if (!str)
		return ((char *)ft_calloc(size, 1));
	new = ft_calloc(size, 1);
	if (!new)
		return (NULL);
	ft_strlcpy(new, str, size);
	ft_free((void **)&str);
	return (new);
}
