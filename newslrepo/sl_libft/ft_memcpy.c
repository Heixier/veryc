/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsiah <rsiah@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 18:04:12 by rsiah             #+#    #+#             */
/*   Updated: 2024/05/15 18:04:12 by rsiah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Copy N bytes of SRC to DEST.
 */
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	void	*start_dest;

	if (!dest && !src)
		return (dest);
	start_dest = dest;
	while (n--)
		*((unsigned char *)dest++) = *((unsigned char *)src++);
	return (start_dest);
}

// int	main(int argc, char **argv)
// {
// 	if (argc == 3)
// 	{
// 		unsigned char	*dest = malloc(sizeof(unsigned char) * 
// 		strlen(argv[1]) + 1);
// 		unsigned char	*expect_dest = malloc(sizeof(unsigned char) * 
// 		strlen(argv[1]));
// 		printf("[Before]\nOutput: %s\nExpect: %s\n\n", dest, expect_dest);
// 		ft_memcpy(dest, argv[1], atoi(argv[2]));
// 		memcpy(expect_dest, argv[1], atoi(argv[2]));
// 		printf("[After]\nOutput: %s\nExpect: %s\n", dest, expect_dest);
// 	}
// 	return (EXIT_SUCCESS);
// }