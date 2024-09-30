/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsiah <rsiah@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 22:11:10 by rsiah             #+#    #+#             */
/*   Updated: 2024/05/23 22:11:11 by rsiah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	ln;

	ln = (long)n;
	if (ln < 0)
	{
		write(fd, "-", 1);
		ln = -ln;
	}
	if (ln >= 10)
		ft_putnbr_fd(ln / 10, fd);
	ft_putchar_fd(('0' + ln % 10), fd);
}

// int	main(int argc, char **argv)
// {
// 	(void)argc;
// 	printf("Output:\n");
// 	ft_putnbr_fd(atoi(argv[1]), 0);
// 	printf("\nExpected:\n%d\n", atoi(argv[1]));
// 	return (EXIT_SUCCESS);
// }
