/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsiah <rsiah@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 17:44:33 by rsiah             #+#    #+#             */
/*   Updated: 2024/05/14 17:44:33 by rsiah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Returns 1 if C is an ASCII character, else return 0.
 */
int	ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
}

// is_ascii returns 1 instead of some other number
//
// int	main(void)
// {
// 	for (int i = -10; i < 200; i++)
// 	{
// 		if (ft_isascii(i) != isascii(i))
// 		{
// 			printf("Failure...\n");
// 			printf("Output: %d\n", ft_isascii(i));
// 			printf("Expected: %d\n", isascii(i));
// 		}
// 	}
// 	return (EXIT_SUCCESS);
// }
