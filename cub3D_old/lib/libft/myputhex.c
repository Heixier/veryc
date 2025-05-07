/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   myputhex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsiah <rsiah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 19:10:45 by anteo             #+#    #+#             */
/*   Updated: 2024/11/21 18:16:42 by rsiah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	myputhex(unsigned long long hex, char *base, t_buffer *buff, int fd)
{
	if (hex == 0)
	{
		fill_buffer(buff, '0', fd);
		return ;
	}
	if (hex >= 16)
		myputhex((hex / 16), base, buff, fd);
	fill_buffer(buff, base[hex % 16], fd);
}
