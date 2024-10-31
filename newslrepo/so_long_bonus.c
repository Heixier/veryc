/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsiah <rsiah@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 18:50:46 by rsiah             #+#    #+#             */
/*   Updated: 2024/10/17 18:50:47 by rsiah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	main(int argc, char **argv)
{
	t_map	*map;
	t_game	*game;

	if (argc != 2)
		return (1);
	map = init_map(argv[1]);
	if (!map)
		return (1);
	if (!validate_map(map))
		return (free_map(map), 1);
	game = init_game(map);
	if (!game)
		return (free_game(game), 1);
	run_game(game);
	return (free_game(game), 0);
}
