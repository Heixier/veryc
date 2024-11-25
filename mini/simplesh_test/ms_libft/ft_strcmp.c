/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsiah <rsiah@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 15:51:23 by rsiah             #+#    #+#             */
/*   Updated: 2024/09/20 15:51:33 by rsiah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/** Compares two strings and returns the difference*/
int	ft_strcmp(const char *s1, const char *s2)
{	
	size_t			i;
	unsigned char	*us1;
	unsigned char	*us2;

	us1 = (unsigned char *)s1;
	us2 = (unsigned char *)s2;
	if (!s1 || !s2)
		return (-1);
	i = 0;
	while (us1[i] && us1[i] == us2[i])
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