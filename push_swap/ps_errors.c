/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsiah <rsiah@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 13:49:59 by rsiah             #+#    #+#             */
/*   Updated: 2024/08/29 13:50:21 by rsiah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"

static int	is_string_numeric(char *str)
{
	while (*str)
	{
		if (*str == '-')
			str++;
		if (*str < '0' || *str > '9')
			return (0);
		str++;
	}
	return (1);
}

static int	error_non_numeric(int items, char **argv)
{
	while (items > 0)
	{
		if (!(is_string_numeric(argv[items - 1])))
			return (1);
		items--;
	}
	return (0);
}

static int	error_overflow(int items, char **argv)
{
	while (items > 0)
	{
		if (ps_atoll(argv[items - 1]) != ps_atoi(argv[items - 1]))
			return (1);
		items--;
	}
	return (0);
}

static int	error_duplicate(int items, char **argv)
{
	int		current;
	int		occurences;
	int		i;

	while (items > 0)
	{
		i = 0;
		occurences = 0;
		current = ps_atoll(argv[items - 1]);
		while (argv[i])
		{
			if (current == ps_atoll(argv[i]))
				occurences++;
			if (occurences > 1)
				return (1);
			i++;
		}
		items--;
	}
	return (0);
}

int	ps_check_error(int items, char **argv)
{
	if (error_non_numeric(items, argv) || \
error_overflow(items, argv) || error_duplicate(items, argv))
		return (1);
	return (0);
}
