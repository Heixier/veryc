/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsiah <rsiah@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 16:16:56 by rsiah             #+#    #+#             */
/*   Updated: 2024/05/14 16:16:57 by rsiah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Converts lowercase letters to uppercase. 
 */
int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c + ('A' - 'a'));
	return (c);
}

// int	main(int argc, char **argv)
// {
// 	if (argc == 2)
// 	{
// 		printf("Output: %d\n", ft_toupper(*argv[1]));
// 		printf("Expected: %d\n", toupper(*argv[1]));
// 	}
// 	return (EXIT_SUCCESS);
// }