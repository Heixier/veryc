/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsiah <rsiah@42singapore.sg>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 18:39:38 by anteo             #+#    #+#             */
/*   Updated: 2025/04/12 13:01:19 by rsiah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z')
		|| (c >= 'A' && c <= 'Z'))
		return (1024);
	else
		return (0);
}

// Returns 1024 if string is alphabetical
int	ft_arealphas(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (!((str[i] >= 'a' && str[i] <= 'z') || \
(str[i] >= 'A' && str[i] <= 'Z')))
			return (0);
		i++;
	}
	return (1024);
}
