/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsiah <rsiah@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 12:24:11 by rsiah             #+#    #+#             */
/*   Updated: 2024/05/15 12:24:11 by rsiah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Returns 16384 if C is a printable character, else return 0.
 */
int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (16384);
	return (0);
}

// int	main(void)
// {
// 	int c;

// 	for (c = 0; c <= 127; c++)
// 	{
// 		if (ft_isprint(c) != isprint(c))
// 		{
// 			printf("Case: %c\n", c);
// 			printf("Failure!\n");
// 			return (EXIT_SUCCESS);
// 		}
// 	}
// 	printf("Success!\n");
// 	return (EXIT_SUCCESS);
// }
