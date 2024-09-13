/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_lib_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsiah <rsiah@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 14:09:18 by rsiah             #+#    #+#             */
/*   Updated: 2024/08/29 14:09:31 by rsiah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"

long long	ps_atoll(const char *nptr)
{
	long long	i;
	long long	output;
	int			sign;

	i = 0;
	output = 0;
	sign = 1;
	if (nptr[i] == '-')
	{
		sign *= -1;
		i++;
	}
	else if (nptr[i] == '+')
		i++;
	while ((nptr[i]) >= '0' && (nptr[i]) <= '9')
	{
		output *= 10;
		output += nptr[i] - '0';
		i++;
	}
	return (output * sign);
}

/**
 * Compares two strings S1 and S2 and returns the difference.
 */
int	ps_strcmp(const char *s1, const char *s2)
{	
	size_t			i;
	unsigned char	*us1;
	unsigned char	*us2;

	us1 = (unsigned char *)s1;
	us2 = (unsigned char *)s2;
	i = 0;
	while (us1[i] && us1[i] == us2[i])
		i++;
	return (us1[i] - us2[i]);
}

/**
 * Convert char type to int type.
 */
int	ps_atoi(const char *nptr)
{
	int	i;
	int	output;
	int	sign;

	i = 0;
	output = 0;
	sign = 1;
	if (nptr[i] == '-')
	{
		sign *= -1;
		i++;
	}
	else if (nptr[i] == '+')
		i++;
	while ((nptr[i]) >= '0' && (nptr[i]) <= '9')
	{
		output *= 10;
		output += nptr[i] - '0';
		i++;
	}
	return (output * sign);
}
