/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsiah <rsiah@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 20:59:17 by rsiah             #+#    #+#             */
/*   Updated: 2024/05/13 20:59:21 by rsiah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Returns 8 if C is alphanumerical, else return 0.
 */
int	ft_isalnum(int c)
{
	if (ft_isdigit(c) || ft_isalpha(c))
		return (8);
	return (0);
}

// int	main(int argc, char **argv)
// {
// 	if (argc > 1)
// 	{
// 		printf("Output: %d\n", ft_isalnum(*argv[1]));
// 		printf("Expected: %d\n", isalnum(*argv[1]));
// 	}
// 	return (0);
// }