/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsiah <rsiah@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 15:28:12 by rsiah             #+#    #+#             */
/*   Updated: 2024/05/22 15:28:13 by rsiah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	length_of(long n)
{
	size_t	output_length;

	output_length = 1;
	if (n < 0)
	{
		n = -n;
		output_length++;
	}
	while (n >= 10)
	{
		output_length++;
		n /= 10;
	}
	return (output_length);
}

char	*ft_itoa(int n)
{
	char	*output;
	long	ln;
	size_t	length;

	ln = (long)n;
	length = length_of(ln);
	output = ft_calloc(length + 1, sizeof(char));
	if (!output)
		return (output);
	if (ln < 0)
	{
		output[0] = '-';
		ln = -ln;
	}
	while (length && ln)
	{
		output[length - 1] = (char)('0' + (ln % 10));
		ln /= 10;
		length--;
	}
	if (!*output)
		*output = '0';
	return (output);
}

// int	main(int argc, char **argv)
// {
// 	if (argc == 2)
// 	{
// 		printf("Length: %ld\nitoa: %s\n", 
// 		length_of(atoi(argv[1])), ft_itoa(atoi(argv[1])));
// 	}
// 	return (EXIT_SUCCESS);
// }