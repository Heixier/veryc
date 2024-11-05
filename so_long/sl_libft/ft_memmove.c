/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsiah <rsiah@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 22:32:33 by rsiah             #+#    #+#             */
/*   Updated: 2024/05/15 22:32:33 by rsiah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Copy N bytes of SRC to DEST, guaranteeing
 * correct behavior for overlapping strings.
 */
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	void	*start_dest;

	start_dest = dest;
	if (dest < src)
		while (n--)
			*((unsigned char *)dest++) = *((unsigned char *)src++);
	else if (dest > src)
		while (n--)
			((unsigned char *)dest)[n] = ((unsigned char *)src)[n];
	return (start_dest);
}

// This main doesn't check for overlapping regions
// int	main(int argc, char **argv)
// {
// 	if (argc == 3)
// 	{
// 		unsigned char	*dest = malloc(sizeof(unsigned char) * 
// 		strlen(argv[1] + 1));
// 		unsigned char	*expect_dest = malloc(sizeof(unsigned char) * 
// 		strlen(argv[1] + 1));
// 		printf("[Before]\nOutput: %s\nExpect: %s\n\n", dest, 
// 		expect_dest);
// 		ft_memmove(dest, argv[1], atoi(argv[2]));
// 		memmove(expect_dest, argv[1], atoi(argv[2]));
// 		printf("[After]\nOutput: %s\nExpect: %s\n", dest, 
// 		expect_dest);
// 	}
// 	return (EXIT_SUCCESS);
// }