/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsiah <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 20:45:53 by rsiah             #+#    #+#             */
/*   Updated: 2024/05/13 20:45:55 by rsiah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Returns 1024 if C is alphabetical, else return 0.
 */
int	ft_isalpha(int c)
{
	return (((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) * 1024);
}

// int	main(int argc, char **argv)
// {
// 	if (argc > 1)
// 	{
// 		printf("Output: %d\n", ft_isalpha(*argv[1]));
// 		printf("Expected: %d\n", isalpha(*argv[1]));
// 	}
// 	return (0);
// }