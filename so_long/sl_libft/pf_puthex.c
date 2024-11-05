/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsiah <rsiah@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 17:10:12 by rsiah             #+#    #+#             */
/*   Updated: 2024/06/19 17:10:13 by rsiah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_hexa(unsigned int n)
{
	int	count;

	count = 1;
	while (n >= 16)
	{
		count++;
		n /= 16;
	}
	return (count);
}

static void	write_in_hex(unsigned int hexa, int upper, int fd)
{
	if (upper)
	{
		if (hexa >= 16)
			write_in_hex(hexa / 16, upper, fd);
		pf_putchar("0123456789ABCDEF"[hexa % 16], fd);
	}
	else
	{
		if (hexa >= 16)
			write_in_hex(hexa / 16, upper, fd);
		pf_putchar("0123456789abcdef"[hexa % 16], fd);
	}
}

int	pf_puthex(unsigned int hexa, int upper, int fd)
{
	int	count;

	count = 0;
	write_in_hex(hexa, upper, fd);
	count += count_hexa(hexa);
	return (count);
}

// int main(int argc, char **argv)
// {
// 	(void)argc;
// 	int my_res = pf_puthex(atoi(argv[1]), atoi(argv[2]));
// 	int actl_res;
// 	printf("\nMy count: %d\n", my_res);
// 	if (atoi(argv[2]))
// 		actl_res = printf("%X", atoi(argv[1]));
// 	else
// 		actl_res = printf("%x", atoi(argv[1]));
// 	printf("\nActl count: %d\n", actl_res);
// 	return (0);
// }