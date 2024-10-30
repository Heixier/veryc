/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsiah <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 20:52:58 by rsiah             #+#    #+#             */
/*   Updated: 2024/05/13 20:53:01 by rsiah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Returns 2048 if C is numerical, else return 0.
 */
int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (2048);
	return (0);
}

// int	main(int argc, char **argv)
// {
// 	if (argc > 1)
// 	{
// 		printf("Output: %d\n", ft_isdigit(*argv[1]));
// 		printf("Expected: %d\n", isdigit(*argv[1]));
// 	}
// 	return (0);
// }