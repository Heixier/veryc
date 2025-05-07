/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anteo <anteo@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 21:54:35 by anteo             #+#    #+#             */
/*   Updated: 2024/05/27 17:53:42 by anteo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_overlap(unsigned char *tp_d, const unsigned char *tp_s, size_t n)
{
	unsigned int		i;

	if (tp_d < tp_s && tp_d <= tp_s + n)
	{
		i = 0;
		while (i < n)
		{
			tp_d[i] = tp_s[i];
			i++;
		}
	}
	else if (tp_d > tp_s)
	{
		i = n;
		while (i-- > 0)
			tp_d[i] = tp_s[i];
	}
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*tmp_d;
	const unsigned char	*tmp_s;

	tmp_d = (unsigned char *)dest;
	tmp_s = (const unsigned char *)src;
	ft_overlap(tmp_d, tmp_s, n);
	return (dest);
}
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char str[100] = "Hello World with friends && I am confused :)";
	printf( "Function:\tft_memmove with overlap\n" );
	printf( "Orignal :\t%s\n",str);
	printf( "Source:\t\t%s\n", str + 6);
	printf( "Destination:\t%s\n", str + 12);
	ft_memmove(str + 12, str + 6, 45);
	printf( "Result:\t\t%s\n\n", str);

	char str1[100] = "Hello World with friends && I am confused :)";
	printf( "Function:\tmemmove with overlap\n" );
	printf( "Orignal :\t%s\n",str1);
	printf( "Source:\t\t%s\n", str1 + 6);
	printf( "Destination:\t%s\n", str1 + 12);
	memmove(str1 + 12, str1 + 6, 45);
	printf( "Result:\t\t%s\n", str1);
	return 0;
}
*/
