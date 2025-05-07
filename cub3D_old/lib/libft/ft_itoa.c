/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anteo <anteo@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 20:20:25 by anteo             #+#    #+#             */
/*   Updated: 2024/05/27 23:14:04 by anteo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	cnt_digit(int n)
{
	int	flag;

	flag = 0;
	if (n < 0)
	{
		n *= -1;
		flag++;
	}
	flag++;
	while (n >= 10)
	{
		n = n / 10;
		flag++;
	}
	return (flag);
}

void	makestr(int d_cnt, char *ptr, int n)
{
	unsigned int	i;

	i = d_cnt - 1;
	if (n < 0)
	{
		ptr[0] = '-';
		n *= -1;
	}
	while (n != 0)
	{
		ptr[i] = (n % 10) + '0';
		n /= 10;
		i--;
	}
	ptr[d_cnt] = '\0';
}

char	*ft_itoa(int n)
{
	int			d_cnt;
	char		*ptr;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	d_cnt = cnt_digit(n);
	ptr = (char *)malloc((d_cnt + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	makestr(d_cnt, ptr, n);
	return (ptr);
}
/*
#include <stdio.h>

int	main(void)
{
	int n = 9;
	char *res = ft_itoa(n);

	printf("if int is %d: %s\n", n, res);
	free(res);
	return (0);
}
*/
