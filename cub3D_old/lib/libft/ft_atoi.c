/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsiah <rsiah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 04:32:38 by anteo             #+#    #+#             */
/*   Updated: 2025/01/16 16:06:49 by rsiah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(char *str)
{
	if (*str == ' ' || *str == '\n'
		|| *str == '\t' || *str == '\v'
		|| *str == '\f' || *str == '\r')
		return (1);
	else
		return (0);
}

int	ft_atoi(const char *nptr)
{
	int	neg;
	int	res;

	neg = 1;
	res = 0;
	while (ft_isspace((char *)nptr) == 1)
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			neg = -1;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		res = (res * 10) + (*nptr - '0');
		nptr++;
	}
	return (res * neg);
}

long long	ft_atoll(const char *nptr)
{
	long long	output;
	int			sign;

	sign = 1;
	output = 0;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			sign = -sign;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		output = (output * 10) + (*nptr - '0');
		nptr++;
	}
	return (output * sign);
}
/*
#include <stdio.h>
int     main(int argc, char **argv)
{
        if (argc == 2)
        {
                int     str_print;

                str_print = ft_atoi(argv[1]);
                printf("%d\n", str_print);
        }
}
*/
