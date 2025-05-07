/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsiah <rsiah@42singapore.sg>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 18:40:09 by anteo             #+#    #+#             */
/*   Updated: 2025/04/12 13:01:04 by rsiah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if ((c >= 'a' && c <= 'z') || \
(c >= 'A' && c <= 'Z') || \
(c >= '0' && c <= '9'))
		return (8);
	else
		return (0);
}

// Returns 8 if string is alphanumerical
int	ft_arealnums(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (!((str[i] >= 'a' && str[i] <= 'z') || \
(str[i] >= 'A' && str[i] <= 'Z') || \
(str[i] >= '0' && str[i] <= '9')))
			return (0);
		i++;
	}
	return (8);
}
