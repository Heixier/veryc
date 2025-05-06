/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   myputnbr_fd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsiah <rsiah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 19:30:18 by anteo             #+#    #+#             */
/*   Updated: 2024/11/21 18:16:47 by rsiah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	myputnbr_fd(int n, int fd, t_buffer *buff)
{
	if (n == -2147483648)
	{
		fill_buffer(buff, '-', fd);
		fill_buffer(buff, '2', fd);
		n = 147483648;
	}
	if (n < 0)
	{
		fill_buffer(buff, '-', fd);
		n *= -1;
	}
	if (n >= 10)
	{
		myputnbr_fd((n / 10), fd, buff);
		myputnbr_fd((n % 10), fd, buff);
	}
	else
		fill_buffer(buff, (n + '0'), fd);
}
