/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsiah <rsiah@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 16:38:38 by rsiah             #+#    #+#             */
/*   Updated: 2024/06/18 16:38:39 by rsiah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	write_arg(int fd, va_list args, char fmt)
{
	if (fmt == 'c')
		return (pf_putchar(va_arg(args, int), fd));
	else if (fmt == 's')
		return (pf_putstring(va_arg(args, char *), fd));
	else if (fmt == 'p')
		return (pf_putaddr(va_arg(args, void *), fd));
	else if (fmt == 'd' || fmt == 'i')
		return (pf_putnbr(va_arg(args, int), fd));
	else if (fmt == 'u')
		return (pf_putnbr_u(va_arg(args, unsigned int), fd));
	else if (fmt == 'X')
		return (pf_puthex(va_arg(args, unsigned int), 1, fd));
	else if (fmt == 'x')
		return (pf_puthex(va_arg(args, unsigned int), 0, fd));
	else if (fmt == '%')
		return (write(1, "%%", 1), 1);
	else
		return (-1);
}

/** Prints a string to a specified file descriptor. */
int	ft_printfd(int fd, const char *str, ...)
{
	va_list	args;
	int		return_val;

	return_val = 0;
	va_start(args, str);
	while (str && *str)
	{
		if (*str == '%')
		{
			str++;
			return_val += write_arg(fd, args, *str);
			str++;
		}
		else
		{
			write(fd, str, 1);
			str++;
			return_val++;
		}
	}
	return (return_val);
}

// int	main(void)
// {
// 	int my_return;
// 	int actl_return;
// 	char	*main_str = "Hello%cwo%url%x%Xd\n%s%p%%%%%%%%%%\n";
// 	char	*str2 = "stringy";

// 	printf("Mine:\n\n");
// 	my_return = ft_printf(main_str, 'Z', 15, 73, 82, str2, &str2);
// 	printf("\nActl:\n\n");
// 	actl_return = printf(main_str, 'Z', 15, 73, 82, str2, &str2);
// 	if (my_return == actl_return)
// 		printf("\nReturn of %d matches!\n", my_return);
// 	else
// 		printf("Return mismatch!\nMine: %d\nActl: %d\n", my_return, actl_return);
// 	return (0);
// }
