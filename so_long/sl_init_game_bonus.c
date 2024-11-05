/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_init_game_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsiah <rsiah@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 20:57:05 by rsiah             #+#    #+#             */
/*   Updated: 2024/10/23 20:57:06 by rsiah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	sl_init_win(t_game *game, t_map *map)
{
	int	x;
	int	y;
	int	screen_x;
	int	screen_y;

	mlx_get_screen_size(game -> mlx, &screen_x, &screen_y);
	x = (map -> width * IMG_SIZE) + PADDING;
	y = map -> height * IMG_SIZE + PADDING;
	if (x > screen_x || y > screen_y - (game -> tile_size * 4))
		return (ft_printfd(2, "Error\nwindow size exceeds display\n\
Available screen resolution: %dx%d\n\
Requested screen resolution: %dx%d\n", screen_x, \
screen_y - game -> tile_size * 4, x, y), 0);
	game -> tile_size = IMG_SIZE;
	game -> win = mlx_new_window(game -> mlx, x, y, WIN_TITLE);
	if (!game -> win)
		return (ft_printfd(2, "Error\nfailed to create window\n"), 0);
	return (1);
}

int	init_images(t_game *game)
{
	game -> bg_img = mlx_xpm_file_to_image(game -> mlx, BG_PATH, \
	&game -> tile_size, &game -> tile_size);
	game -> tile_img = mlx_xpm_file_to_image(game -> mlx, TILE_PATH, \
	&game -> tile_size, &game -> tile_size);
	game -> player_img = mlx_xpm_file_to_image(game -> mlx, PLAYER_PATH, \
	&game -> tile_size, &game -> tile_size);
	game -> token_img = mlx_xpm_file_to_image(game -> mlx, TOKEN_PATH, \
	&game -> tile_size, &game -> tile_size);
	game -> exit_closed_img = mlx_xpm_file_to_image(game -> mlx, EXIT_CLOSED, \
	&game -> tile_size, &game -> tile_size);
	game -> exit_open_img = mlx_xpm_file_to_image(game -> mlx, EXIT_OPEN, \
	&game -> tile_size, &game -> tile_size);
	if (!game -> bg_img || !game -> tile_img || !game -> player_img || \
	!game -> token_img || !game -> exit_closed_img || \
	!game -> exit_open_img)
		return (0);
	return (1);
}

t_playr	*init_player(t_map *map)
{
	t_playr	*player;

	player = malloc(sizeof(t_playr));
	if (!player)
		return (NULL);
	player -> on_exit = 0;
	player -> tokens = 0;
	player -> x = map -> player_x;
	player -> y = map -> player_y;
	map -> player_x = -999;
	map -> player_y = -999;
	return (player);
}

void	*init_game(t_map *map)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	if (!game)
		return (NULL);
	game -> player = init_player(map);
	if (!game -> player)
		return (free(game), NULL);
	game -> win = NULL;
	game -> mlx = mlx_init();
	game -> map = map;
	game -> moves = 0;
	game -> victory = 0;
	if (!init_images(game))
		return (ft_printfd(2, "Error\nfailed to load images\n"), \
		free_game(game), NULL);
	if (!game -> mlx)
		return (ft_printfd(2, "Error\nfailed to init mlx\n"), \
		free_game(game), NULL);
	if (!sl_init_win(game, map))
		return (ft_printfd(2, "Error\nwin fail\n"), free_game(game), NULL);
	return (game);
}
