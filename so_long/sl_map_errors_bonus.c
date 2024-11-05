/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_map_errors_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsiah <rsiah@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 18:50:12 by rsiah             #+#    #+#             */
/*   Updated: 2024/10/17 18:50:12 by rsiah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	map_print_errors(t_merr *errors, t_map *map)
{
	if (errors -> errors)
	{
		ft_printfd(2, "Error\n%d errors found!\n", errors -> errors);
		if (errors -> shape)
			ft_printfd(2, "invalid shape!\n");
		if (errors -> characters)
			ft_printfd(2, "invalid characters: %d\n", errors -> characters);
		if (errors -> left_wall)
			ft_printfd(2, "%d breaks in left wall!\n", errors -> left_wall);
		if (errors -> right_wall)
			ft_printfd(2, "%d breaks in right wall!\n", errors -> right_wall);
		if (errors -> top_wall)
			ft_printfd(2, "%d breaks in top wall!\n", errors -> top_wall);
		if (errors -> bottom_wall)
			ft_printfd(2, "%d breaks in bottom wall!\n", errors -> bottom_wall);
		if (errors -> tokens)
			ft_printfd(2, "invalid collectibles: %d\n", map -> tokens);
		if (errors -> exits)
			ft_printfd(2, "invalid exits: %d\n", map -> exits);
		if (errors -> players)
			ft_printfd(2, "invalid players: %d\n", map -> players);
	}
}

/** Returns number of errors found */
int	map_tally_errors(t_merr *errors, t_map *map)
{
	if (errors -> shape)
		errors -> errors++;
	if (errors -> characters)
		errors -> errors++;
	if (errors -> left_wall)
		errors -> errors++;
	if (errors -> right_wall)
		errors -> errors++;
	if (errors -> top_wall)
		errors -> errors++;
	if (errors -> bottom_wall)
		errors -> errors++;
	if (errors -> tokens)
		errors -> errors++;
	if (errors -> exits)
		errors -> errors++;
	if (errors -> players)
		errors -> errors++;
	return (map_print_errors(errors, map), errors -> errors);
}

/** Create error struct and checks for errors */
t_merr	*set_errors(t_map *map)
{
	t_merr	*errors;

	errors = ft_calloc(sizeof(t_merr), 1);
	if (!errors)
		return (NULL);
	if (!map)
		return (NULL);
	map_check_shape(map, errors);
	map_check_walls(map, errors);
	map_check_items(map, errors);
	return (errors);
}

int	validate_map(t_map *map)
{
	t_merr	*errors;

	errors = set_errors(map);
	if (!errors)
		return (ft_printfd(2, "Error\nFailed to create t_error\n"), 0);
	if (map_tally_errors(errors, map) > 0 || !map_check_path(map))
		return (ft_printfd(2, "Error\nFailed to validate map!\n"), \
		free(errors), 0);
	return (free(errors), 1);
}
