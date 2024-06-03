/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsiah <rsiah@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 14:54:38 by rsiah             #+#    #+#             */
/*   Updated: 2024/05/18 14:54:40 by rsiah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Returns a pointer to a new NUL-terminated string 
 * which is a duplicate of the string S. (uses malloc)
 */
char	*ft_strdup(const char *s)
{
	char	*output;

	output = ft_calloc(ft_strlen(s) + 1, sizeof(char));
	if (!output)
		return (output);
	else
		return (ft_memcpy(output, s, ft_strlen(s)), output);
}

// int	main(int argc, char **argv)
// {
// 	if (argc == 2)
// 	{
// 		char	*my_output = ft_strdup(argv[1]);
// 		char	*their_output = strdup(argv[1]);
// 		printf("Output: %s\nExpect: %s\n", my_output, their_output);
// 		if (my_output != their_output && my_output != argv[1])
// 			printf("Successfully duplicated to address: %p\n", my_output);
// 		else
// 			printf("Failed to duplicate to a different address...\n");
// 		free(my_output);
// 		free(their_output);
// 	}
// 	return (EXIT_SUCCESS);
// }