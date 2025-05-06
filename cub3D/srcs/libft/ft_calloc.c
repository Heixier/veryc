/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anteo <anteo@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 05:12:33 by anteo             #+#    #+#             */
/*   Updated: 2024/05/31 22:29:30 by anteo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//Malloc but initialises all bytes to zero
void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t			total_size;
	void			*ptr;
	unsigned int	cnt;

	if (size != 0 && nmemb > SIZE_MAX / size)
		return (NULL);
	total_size = nmemb * size;
	ptr = malloc(total_size);
	if (ptr == NULL)
		return (NULL);
	cnt = 0;
	while (cnt < total_size)
	{
		((unsigned char *)ptr)[cnt] = 0;
		cnt++;
	}
	return (ptr);
}
/*
#include <stdlib.h>
#include <limits.h>
int	main(void)
{
	char *str1 = calloc(1, 2147483648);
	char *str2 = ft_calloc(1, 2147483648);
	free(str1);
	free(str2);
	return (0);
}
*/
