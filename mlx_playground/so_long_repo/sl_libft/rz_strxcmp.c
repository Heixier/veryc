/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comparisons.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsiah <rsiah@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 15:51:23 by rsiah             #+#    #+#             */
/*   Updated: 2024/09/20 15:51:33 by rsiah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/** Returns the difference between strings up to N, 
 * otherwise compares whole string if N <= 0*/
int	rz_strxcmp(const char *s1, const char *s2, size_t x)
{	
	size_t			i;
	unsigned char	*us1;
	unsigned char	*us2;

	us1 = (unsigned char *)s1;
	us2 = (unsigned char *)s2;
	if (!s1 || !s2)
		return (-1);
	i = 0;
	if (!x)
		while (us1[i] && us1[i] == us2[i])
			i++;
	else
		while (us1[i] && us1[i] == us2[i] && i < x - 1)
			i++;
	return (us1[i] - us2[i]);
}

// int	main(int argc, char **argv)
// {
// 	if (argc != 4)
// 		return (-1);
// 	printf("Diff: %d\n", rz_strxcmp(argv[1], argv[2], atoi(argv[3])));
// 	return (0);
// }