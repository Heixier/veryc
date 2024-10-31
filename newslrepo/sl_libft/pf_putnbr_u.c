/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_putnbr_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsiah <rsiah@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 17:07:09 by rsiah             #+#    #+#             */
/*   Updated: 2024/06/19 17:07:11 by rsiah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_digits(unsigned int n)
{
	int	count;

	count = 1;
	while (n >= 10)
	{
		count++;
		n /= 10;
	}
	return (count);
}

int	pf_putnbr_u(unsigned int n, int fd)
{
	int		count;

	count = 0;
	if (n >= 10)
		pf_putnbr_u(n / 10, fd);
	count += count_digits(n);
	return (pf_putchar((n % 10) + '0', fd), count);
}

// int main(int argc, char **argv)
// {
// 	(void)argc;
// 	int return_val = pf_putnbr_u(atoi(argv[1]));
// 	printf("\nReturn value: %d\n", return_val);
// 	int actl_val = printf("%u", atoi(argv[1]));
// 	printf("\nActual return: %d\n", actl_val);
//     return (0);
// }
