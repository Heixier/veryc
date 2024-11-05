/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsiah <rsiah@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 15:05:40 by rsiah             #+#    #+#             */
/*   Updated: 2024/05/15 15:05:41 by rsiah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Sets N bytes to zeroes starting from S.
 */
void	ft_bzero(void *s, size_t n)
{
	char	*proxy;

	proxy = s;
	while (n)
	{
		*proxy = '\0';
		proxy++;
		n--;
	}
}

// int	main(int argc, char **argv)
// {
// 	if (argc == 2)
// 	{
// 		size_t n = atoi(argv[1]);

// 		char	*random_address = malloc(sizeof(char) * n);
// 		char	*to_free = random_address;
// 		ft_bzero(random_address, n);
// 		write(1, "Output: ", 8);
// 		for (size_t i = 0; i < n; i++)
// 		{
// 			write(1, random_address, 1);
// 			random_address++;
// 		}
// 		write(1, "\nExpect: ", 9);
// 		random_address = to_free;
// 		bzero(random_address, n);
// 		for (size_t i = 0; i < n; i++)
// 		{
// 			write(1, random_address, 1);
// 			random_address++;
// 		}
// 		write(1, "\n", 1);
// 		free(to_free);
// 	}
// 	return (EXIT_SUCCESS);
// }