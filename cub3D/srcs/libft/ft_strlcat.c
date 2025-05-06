/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anteo <anteo@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 16:01:46 by anteo             #+#    #+#             */
/*   Updated: 2024/05/31 16:24:38 by anteo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t			d_len;
	size_t			s_len;
	unsigned int	i;
	unsigned int	j;

	s_len = ft_strlen(src);
	if (size == 0)
		return (s_len);
	d_len = ft_strlen(dst);
	i = d_len;
	j = 0;
	if (size > d_len)
	{
		while (src[j] && (i < (size - 1)) && j < s_len)
		{
			dst[i] = src[j];
			i++;
			j++;
		}
		dst[i] = '\0';
		return (d_len + s_len);
	}
	return (size + s_len);
}
/*
int	main(void)
{
*/
