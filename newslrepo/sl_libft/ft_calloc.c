/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsiah <rsiah@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 16:20:26 by rsiah             #+#    #+#             */
/*   Updated: 2024/05/17 16:20:27 by rsiah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*output;
	size_t	n;

	if (nmemb == 0 || size == 0)
		return (NULL);
	n = nmemb * size;
	if (n / nmemb != size)
		return (NULL);
	output = malloc(n);
	if (!output)
		return (ft_printfd(2, "malloc error\n"), output);
	return (ft_bzero(output, n), output);
}

// int	main(int argc, char **argv)
// {
// 	if (argc == 2)
// 	{
// 		char	*output = ft_calloc(sizeof(int), 
// 		atol(argv[1]));
// 		// char	*output = malloc(atol(argv[1]) * sizeof(char));
// 		if (output)
// 		{
// 			printf("Successfully allocated %ld bytes!\n", 
// 			atol(argv[1]));
// 			for (size_t i = 0; i < (size_t)atol(argv[1]); i++)
// 			{
// 				if (output[i])
// 				{
// 					printf("Oops, found character at: %c", output[i]);
// 					free(output);
// 					return (EXIT_SUCCESS);
// 				}
// 			}
// 			printf("All clean for %ld bytes.\nCalloc success!", 
// 			atol(argv[1]));
// 		}
// 		else
// 			printf("Failed to allocate %ld bytes...\n", 
// 			atol(argv[1]));
// 		free(output);
// 	}
// 	return (EXIT_SUCCESS);
// }