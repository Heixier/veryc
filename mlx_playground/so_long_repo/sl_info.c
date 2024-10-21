/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_info.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsiah <rsiah@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 18:50:06 by rsiah             #+#    #+#             */
/*   Updated: 2024/10/17 18:50:07 by rsiah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_array(char **array, char *msg)
{
	int	i;

	i = 0;
	if (array)
	{
		ft_printfd(1, "%s", msg);
		while (array[i])
		{
			ft_printfd(1, "%d: %s\n", i, array[i]);
			i++;
		}
	}
}

void	print_map(t_map *map)
{
	ft_printfd(1, "Mapstr [%d]: \t\n%s\n", map -> size, map -> mapstr);
	print_array(map -> data, "Array: \n");
	ft_printfd(1, "Width: %d\nHeight: %d\nCollectibles: %d\n\
Exits: %d\nPlayers: %d\n", \
	map -> width, map -> height, map -> tokens, map -> exits, map -> players);
}
