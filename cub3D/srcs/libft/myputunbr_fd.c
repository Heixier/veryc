/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   myputunbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsiah <rsiah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 19:30:18 by anteo             #+#    #+#             */
/*   Updated: 2024/11/21 18:16:59 by rsiah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	myputunbr_fd(unsigned int n, int fd, t_buffer *buff)
{
	if (n >= 10)
	{
		myputunbr_fd((n / 10), fd, buff);
		myputunbr_fd((n % 10), fd, buff);
	}
	else
		fill_buffer(buff, (n + '0'), fd);
}
