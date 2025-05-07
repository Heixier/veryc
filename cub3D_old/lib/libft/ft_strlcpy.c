/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anteo <anteo@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 18:42:24 by anteo             #+#    #+#             */
/*   Updated: 2024/05/26 07:35:46 by jelly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t			s_len;
	unsigned int	i;

	s_len = ft_strlen(src);
	if (size == 0)
		return (s_len);
	i = 0;
	while ((i < size - 1) && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (s_len);
}
//	if (!dst || !src)
//		return (0);
//		add the above two line back to line 21 and 22 after eval

/*
int	main(void)
{
	char	*dst1 = "Hello";
	char	*src1 = "World!";
	int	i = 3;

*/
