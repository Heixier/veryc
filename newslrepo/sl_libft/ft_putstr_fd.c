/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsiah <rsiah@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 21:59:46 by rsiah             #+#    #+#             */
/*   Updated: 2024/05/23 21:59:47 by rsiah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	if (s)
		write(fd, s, ft_strlen(s));
}

// int	main(int argc, char **argv)
// {
// 	(void)argc;
// 	ft_putstr_fd(argv[1], atoi(argv[2]));
// 	return (EXIT_SUCCESS);
// }
