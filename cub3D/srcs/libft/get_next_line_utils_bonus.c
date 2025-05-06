/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsiah <rsiah@42singapore.sg>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 19:55:23 by anteo             #+#    #+#             */
/*   Updated: 2025/03/03 20:25:34 by rsiah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// size_t	ft_strlen(const char *str)
// {
// 	size_t	len;

// 	if (str == NULL)
// 		return (0);
// 	len = 0;
// 	while (str[len])
// 		len++;
// 	return (len);
// }

char	*gnl_strchr(const char *s, int c)
{
	char	*ts;
	size_t	len;

	ts = (char *)s;
	len = ft_strlen(ts);
	if ((unsigned char)c == '\0')
		return (ts + len);
	while (*ts)
	{
		if (*ts == (unsigned char)c)
			return (ts);
		ts++;
	}
	return (NULL);
}

char	*gnl_substr(const char *s, unsigned int start, size_t len)
{
	char			*ptr;
	size_t			s_len;
	unsigned int	i;

	if (s == NULL)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_strdup(""));
	if (len > s_len - start)
		len = s_len - start;
	ptr = (char *)malloc((len + 1) * sizeof(char));
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (i < len && s[start + i] != '\0')
	{
		ptr[i] = s[start + i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char	*gnl_strjoin(const char *s1, const char *s2)
{
	char			*ptr;
	size_t			total_len;
	unsigned int	i;
	unsigned int	j;

	total_len = ft_strlen(s1) + ft_strlen(s2);
	ptr = (char *)malloc((total_len + 1) * sizeof(char));
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (s1 && s1[i])
	{
		ptr[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2 && s2[j])
	{
		ptr[i + j] = s2[j];
		j++;
	}
	ptr[i + j] = '\0';
	return (ptr);
}
