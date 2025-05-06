/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anteo <anteo@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 17:53:35 by anteo             #+#    #+#             */
/*   Updated: 2024/05/27 18:50:17 by anteo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char			*t_ptr;
	unsigned int	tr_len;
	unsigned int	i;
	unsigned int	j;

	if (set == NULL || s1 == NULL)
		return (NULL);
	if (*s1 == '\0' || (*s1 == '\0' && *set == '\0'))
		return (ft_strdup(""));
	i = 0;
	while (s1[i] != 0 && ft_strchr(set, s1[i]) != NULL)
		i++;
	if (s1[i] == 0)
		return (ft_strdup(""));
	j = ft_strlen(s1) - 1;
	while (ft_strrchr(set, s1[j]) != NULL)
		j--;
	tr_len = (j - i) + 1;
	t_ptr = ft_substr(s1, i, tr_len);
	return (t_ptr);
}
/*
#include <stdio.h>

int	main(void)
{
	char	s1[] = "  \t \t \n   \n\n\n\t";
	char	set[] = " \n\t";
	char	*t_ptr;

	t_ptr = ft_strtrim(s1, set);
	printf("%s\n", t_ptr);

	return (0);
}
*/
