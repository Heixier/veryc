/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_cleanup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsiah <rsiah@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 18:49:57 by rsiah             #+#    #+#             */
/*   Updated: 2024/10/17 18:49:59 by rsiah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* Superfluous conditional checks*/
void	free_mlx(t_game *game)
{
	if (!game)
		return ;
	if (game -> win)
	{
		mlx_destroy_window(game -> mlx, game -> win);
		game -> win = NULL;
	}
	free_image(game -> mlx, game -> bg_img);
	free_image(game -> mlx, game -> tile_img);
	free_image(game -> mlx, game -> player_img);
	free_image(game -> mlx, game -> token_img);
	free_image(game -> mlx, game -> exit_closed_img);
	free_image(game -> mlx, game -> exit_open_img);
	if (game -> mlx)
	{
		mlx_destroy_display(game -> mlx);
		free(game -> mlx);
		game -> mlx = NULL;
	}
	free(game);
	game = NULL;
}

int	free_game(t_game *game)
{
	if (!game)
		return (1);
	free_map(game -> map);
	free(game -> player);
	free_mlx(game);
	return (1);
}
