/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   myputptr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsiah <rsiah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 21:59:33 by anteo             #+#    #+#             */
/*   Updated: 2024/11/21 18:16:52 by rsiah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	myputptr(void *ptr, int fd, t_buffer *buff)
{
	unsigned long long	u_ptr;

	u_ptr = (unsigned long long)ptr;
	if (ptr == NULL)
	{
		myputstr_fd("(nil)", fd, buff);
		return ;
	}
	if (ptr != NULL)
	{
		myputstr_fd("0x", fd, buff);
		myputhex(u_ptr, BASE_LOW, buff, fd);
	}
}
