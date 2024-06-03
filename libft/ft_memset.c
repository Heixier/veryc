/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsiah <rsiah@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 13:11:55 by rsiah             #+#    #+#             */
/*   Updated: 2024/05/15 13:11:56 by rsiah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Set N bytes of S to C.
 */
void	*ft_memset(void *s, int c, size_t n)
{
	void	*start_s;

	start_s = s;
	while (n--)
		*((unsigned char *)s++) = (unsigned char)c;
	return (start_s);
}

// int	main(int argc, char **argv)
// {
// 	if (argc == 3)
// 	{
// 		char c = *argv[1];
// 		size_t n = atoi(argv[2]);

// 		char	*random_address = malloc(sizeof(char) * n + 1);
// 		char	*to_free = random_address;
// 		ft_memset(random_address, c, n);
// 		write(1, "Output: ", 8);
// 		for (size_t i = 0; i <= n; i++)
// 		{
// 			write(1, random_address, 1);
// 			random_address++;
// 		}
// 		write(1, "\nExpect: ", 9);
// 		random_address = to_free;
// 		memset(random_address, c, n);
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