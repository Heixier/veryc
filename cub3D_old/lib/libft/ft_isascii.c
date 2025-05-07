/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anteo <anteo@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 18:40:40 by anteo             #+#    #+#             */
/*   Updated: 2024/05/27 20:21:47 by anteo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* isascii(): checks whether c is a 7-bit unsigned char value
that fits into the ASCII character set.*/

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	else
		return (0);
}
