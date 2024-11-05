/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_validate_map_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsiah <rsiah@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 18:50:36 by rsiah             #+#    #+#             */
/*   Updated: 2024/10/17 18:50:37 by rsiah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	check_walls_x(t_map *map, t_merr *errors);
static void	check_walls_y(t_map *map, t_merr *errors);

void	map_check_shape(t_map *map, t_merr *errors)
{
	int	i;

	i = 0;
	while (map -> data[i])
	{
		if (ft_strlen(map -> data[i]) != ft_strlen(map -> data[0]))
			errors -> shape = 1;
		i++;
	}
	if (!check_no_empty_line(map -> mapstr))
	{
		ft_printfd(2, "Empty line!\n");
		errors -> shape = 1;
	}
}

static void	check_walls_x(t_map *map, t_merr *errors)
{
	int	i;

	i = 0;
	while (map -> data[0][i])
	{
		if (map -> data[0][i] != WALL)
			errors -> top_wall++;
		i++;
	}
	i = 0;
	while (map -> data[map -> height - 1][i])
	{
		if (map -> data[map -> height - 1][i] != WALL)
			errors -> bottom_wall++;
		i++;
	}
}

static void	check_walls_y(t_map *map, t_merr *errors)
{
	int	i;

	i = 0;
	while (map -> data[i])
	{
		if (map -> data[i][0] != WALL)
			errors -> left_wall++;
		i++;
	}
	i = 0;
	while (map -> data[i])
	{
		if (map -> data[i][map -> width - 1] != WALL)
			errors -> right_wall++;
		i++;
	}
}

void	map_check_walls(t_map *map, t_merr *errors)
{
	if (!errors -> shape)
	{
		check_walls_x(map, errors);
		check_walls_y(map, errors);
	}
}

void	map_check_items(t_map *map, t_merr *errors)
{
	if (map -> tokens < MIN_TOKENS)
		errors -> tokens = 1;
	if (map -> exits != 1)
		errors -> exits = 1;
	if (map -> players != 1)
		errors -> players = 1;
	map_check_elements(map, errors);
}
