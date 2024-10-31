/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsiah <rsiah@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 21:44:03 by rsiah             #+#    #+#             */
/*   Updated: 2024/05/23 21:44:05 by rsiah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// static	void	offset_char(unsigned int index, char *str)
// {
// 	unsigned int	offset_amount;

// 	offset_amount = 1;
// 	str[index] += offset_amount;
// }

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	index;

	if (!s || !f)
		return ;
	index = -1;
	while (s[++index])
		f(index, &s[index]);
}

// int	main(int argc, char **argv)
// {
// 	(void)argc;
// 	printf("Before: %s\n", argv[1]);
// 	ft_striteri(argv[1], &offset_char);
// 	printf("After: %s\n", argv[1]);
// }
