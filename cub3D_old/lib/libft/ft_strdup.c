/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anteo <anteo@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 17:53:55 by anteo             #+#    #+#             */
/*   Updated: 2024/10/18 20:02:41 by anteo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char			*ptr;
	size_t			len;
	unsigned int	i;

	if (s == NULL)
		return (NULL);
	len = ft_strlen(s);
	ptr = (char *)malloc((len + 1) * sizeof(char));
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (i <= len)
	{
		ptr[i] = s[i];
		i++;
	}
	return (ptr);
}
