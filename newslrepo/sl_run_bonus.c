/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_run_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsiah <rsiah@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 18:27:27 by rsiah             #+#    #+#             */
/*   Updated: 2024/10/24 18:27:28 by rsiah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	key_handler(int keycode, t_game *game)
{
	if (keycode == 0xff1b)
		mlx_loop_end(game -> mlx);
	move_direction_check(keycode, game);
	return (1);
}

void	victory_handler(t_game *game)
{
	if ((game -> player -> tokens == game -> map -> tokens) && \
	game -> player -> on_exit)
	{
		ft_printfd(1, "You win!\n");
		mlx_loop_end(game -> mlx);
	}
}

/*MALLOC SPAM WOOOOO*/
int	loop_handler(t_game *game)
{
	char	*move_string;

	move_string = ft_itoa(game -> moves);
	victory_handler(game);
	render_frame(game);
	mlx_string_put(game -> mlx, game -> win, \
	game -> player -> x * game -> tile_size, \
	game -> player -> y * game -> tile_size, \
	0xFF00FF, move_string);
	free(move_string);
	return (1);
}

void	render_tile(t_game *game, int x, int y)
{
	char	tile;
	int		tile_size;
	void	*img;

	tile = game -> map -> data[y][x];
	tile_size = game -> tile_size;
	img = NULL;
	if (tile == EMPTY)
		img = game -> bg_img;
	else if (tile == WALL)
		img = game -> tile_img;
	else if (tile == PLAYER)
		img = game -> player_img;
	else if (tile == TOKEN)
		img = game -> token_img;
	else if (tile == EXIT && game -> player -> tokens == game -> map -> tokens)
		img = game -> exit_open_img;
	else if (tile == EXIT)
		img = game -> exit_closed_img;
	mlx_put_image_to_window(game -> mlx, game -> win, img, \
	(x * tile_size), (y * tile_size));
}

int	run_game(t_game *game)
{
	mlx_hook(game -> win, 17, 0L, mlx_loop_end, game -> mlx);
	mlx_key_hook(game -> win, key_handler, game);
	mlx_loop_hook(game -> mlx, loop_handler, game);
	mlx_loop(game -> mlx);
	return (0);
}
