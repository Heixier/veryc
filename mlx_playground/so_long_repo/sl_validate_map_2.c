/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_validate_map_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsiah <rsiah@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 19:02:38 by rsiah             #+#    #+#             */
/*   Updated: 2024/10/17 19:02:51 by rsiah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
