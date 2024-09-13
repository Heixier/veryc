/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsiah <rsiah@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 16:40:19 by rsiah             #+#    #+#             */
/*   Updated: 2024/06/18 16:40:20 by rsiah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	count_digits(long n)
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

int	pf_putnbr(int n)
{
	long	ln;
	int		count;

	ln = (long)n;
	count = 0;
	if (ln < 0)
	{
		write(1, "-", 1);
		ln = -ln;
		count++;
	}
	if (ln >= 10)
		pf_putnbr(ln / 10);
	count += count_digits(ln);
	return (pf_putchar((ln % 10) + '0'), count);
}

// int main(int argc, char **argv)
// {
// 	(void)argc;
// 	int return_val = pf_putnbr(atoi(argv[1]));
// 	printf("\nReturn value: %d\n", return_val);
// 	int actl_val = printf("%d", atoi(argv[1]));
// 	printf("\nActual return: %d\n", actl_val);
//     return (0);
// }