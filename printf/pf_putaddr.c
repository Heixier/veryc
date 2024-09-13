/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_putpointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsiah <rsiah@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 19:08:45 by rsiah             #+#    #+#             */
/*   Updated: 2024/06/08 19:08:46 by rsiah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	write_in_hex(unsigned long hexa)
{
	if (hexa >= 16)
		write_in_hex(hexa / 16);
	pf_putchar("0123456789abcdef"[hexa % 16]);
}

int	pf_putaddr(void *ptr)
{
	unsigned long	ulptr;
	int				len;

	len = 3;
	if (!ptr)
		return (write(1, "(nil)", 5), 5);
	ulptr = (unsigned long)ptr;
	write(1, "0x", 2);
	write_in_hex(ulptr);
	while (ulptr >= 16)
	{
		len++;
		ulptr /= 16;
	}
	return (len);
}

// #include <string.h>
// int main(void)
// {
// 	char *random_string = strdup("hello");
// 	char *null_string = NULL;
// 	int my_output;
// 	int actl_output;
// 	my_output = pf_putpointer(random_string);
// 	printf("\nActual printf:\n");
// 	actl_output = printf("%p", random_string);
// 	printf("\n");
// 	printf("My output: %d\nActual output: %d\n", my_output, actl_output);
// 	return (0);
// }