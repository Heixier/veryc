/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsiah <rsiah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 10:48:07 by rsiah             #+#    #+#             */
/*   Updated: 2025/01/11 12:17:35 by rsiah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
* Returns the length of a string before char C
* -1 on NULL
* If not found, returns length of whole string
*/
int	ft_count_to_c(char *str, char c)
{
	int	i;

	i = 0;
	if (!str || !c)
		return (-1);
	while (str[i] && str[i] != c)
		i++;
	return (i);
}

int	ft_strarrlen(char **arr)
{
	int	i;

	i = 0;
	if (!arr)
		return (0);
	while (arr[i])
		i++;
	return (i);
}
