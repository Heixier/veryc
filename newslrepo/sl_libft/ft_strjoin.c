/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsiah <rsiah@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 16:35:01 by rsiah             #+#    #+#             */
/*   Updated: 2024/05/18 16:35:02 by rsiah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*output;

	output = ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1, sizeof(char));
	if (output)
	{
		ft_strlcat(output, s1, ft_strlen(s1) + 1);
		ft_strlcat(output, s2, ft_strlen(s1) + ft_strlen(s2) + 1);
	}
	return (output);
}

// int	main(int argc, char **argv)
// {
// 	if (argc == 3)
// 	{
// 		char *output = ft_strjoin(argv[1], argv[2]);
// 		printf("Output: %s\n", output);
// 	}
// 	return (EXIT_SUCCESS);
// }