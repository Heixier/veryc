/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_putstring.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsiah <rsiah@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 18:58:22 by rsiah             #+#    #+#             */
/*   Updated: 2024/06/08 18:58:23 by rsiah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printfd.h"

int	pf_putstring(char *str, int fd)
{
	int	len;

	len = 0;
	if (!str)
	{
		write(fd, "(null)", 6);
		return (6);
	}
	while (*str)
	{
		write(fd, str, 1);
		str++;
		len++;
	}
	return (len);
}
