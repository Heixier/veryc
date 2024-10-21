/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsiah <rsiah@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 21:16:58 by rsiah             #+#    #+#             */
/*   Updated: 2024/05/13 21:16:59 by rsiah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	check_space(char c)
{
	return ((c >= 9 && c <= 13) || c == 32);
}

/**
 * Convert char type to int type.
 */
int	ft_atoi(const char *nptr)
{
	int	i;
	int	output;
	int	sign;

	i = 0;
	output = 0;
	sign = 1;
	while (check_space(nptr[i]))
		i++;
	if (nptr[i] == '-')
	{
		sign *= -1;
		i++;
	}
	else if (nptr[i] == '+')
		i++;
	while (ft_isdigit(nptr[i]))
	{
		output *= 10;
		output += nptr[i] - '0';
		i++;
	}
	return (output * sign);
}

// int	main(int argc, char **argv)
// {
// 	if (argc > 1)
// 	{
// 		printf("ft_atoi: %d\n", ft_atoi(argv[1]));
// 		printf("rl_atoi: %d\n", atoi(argv[1]));
// 	}
// 	return (EXIT_SUCCESS);
// }
