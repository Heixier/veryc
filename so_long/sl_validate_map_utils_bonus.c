/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_validate_map_utils_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsiah <rsiah@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 19:02:38 by rsiah             #+#    #+#             */
/*   Updated: 2024/10/17 19:02:51 by rsiah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	find_char(char c, char *seps)
{
	int	i;

	if (!seps)
		return (1);
	i = 0;
	while (seps[i])
	{
		if (c == seps[i])
			return (1);
		i++;
	}
	return (0);
}

/*If we are seeing consecutive newlines, check that it is EOF*/
int	check_if_eof(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}

/**Checks if there are any elements after encountering two newlines in a row*/
int	check_no_empty_line(char *str)
{
	int	i;
	int	consec_nl;

	i = 0;
	consec_nl = 0;
	if (ft_strlen(str) > 0)
	{
		if (str[0] == '\n')
			return (0);
	}
	while (str[i])
	{
		if (str[i] == '\n')
			consec_nl++;
		else
			consec_nl = 0;
		if (consec_nl >= 2)
			return (0);
		i++;
	}
	return (1);
}

void	map_check_elements(t_map *map, t_merr *errors)
{
	int	x;
	int	y;

	y = 0;
	while (map -> data[y])
	{
		x = 0;
		while (map -> data[y][x])
		{
			if (!(find_char(map -> data[y][x], ALLOWED)))
				errors -> characters++;
			x++;
		}
		y++;
	}
}

int	check_extension(char *filename)
{
	return (ft_strrchr(filename, '.') && \
	!rz_strxcmp(ft_strrchr(filename, '.'), ".ber", 0));
}
